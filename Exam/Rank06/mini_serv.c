#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(char *message) {
    write(2, message, strlen(message));
    exit(1);
}

void fatal_error(void) {
    error("Fatal error\n");
}

typedef struct s_client {
    int id;
    char message[110000];
} t_client;

t_client clients[1024];
fd_set fds, rfds, wfds;
int last_id = 0, max_fd = 0;

const int BUF_SIZE = 42 * 1024 * 4;
char rbuf[BUF_SIZE], wbuf[BUF_SIZE];

void register_client(int fd);
void remove_client(int fd);
void handle_message(int read_bytes, int fd);

int main(int ac, char **av) {
    if (ac != 2) {
        error("Wrong number of arguments\n");
    }

    bzero(&clients, sizeof(clients));
    FD_ZERO(&fds);

    struct sockaddr_in servaddr, cli;
    socklen_t len = sizeof(cli);

    // socket create and verification
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fatal_error();
    }
    bzero(&servaddr, sizeof(servaddr));

    max_fd = sockfd;
    FD_SET(sockfd, &fds);

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
    servaddr.sin_port = htons(atoi(av[1]));

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr))) != 0) {
        fatal_error();
    }
    if (listen(sockfd, 10) != 0) {
        fatal_error();
    }

    while (1) {
        rfds = wfds = fds;
        if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0) {
            continue;
        }
        for (int fd = 0; fd <= max_fd; fd++) {
            if (!FD_ISSET(fd, &rfds)) {
                continue;
            }
            if (fd == sockfd) {
                int connfd = accept(sockfd, (struct sockaddr *) &cli, &len);
                if (connfd < 0) {
                    continue;
                }
                if (connfd > max_fd) {
                    max_fd = connfd;
                }
                register_client(connfd);
            } else {
                int read_bytes = recv(fd, rbuf, BUF_SIZE, 0);
                if (read_bytes <= 0) {
                    remove_client(fd);
                } else {
                    handle_message(read_bytes, fd);
                }
            }
            break;
        }
    }
    return 0;
}

void send_message(int except_fd) {
    for (int fd = 0; fd <= max_fd; fd++) {
        if (FD_ISSET(fd, &fds) && fd != except_fd) {
            send(fd, wbuf, strlen(wbuf), 0);
        }
    }
    bzero(&wbuf, BUF_SIZE);
}

void handle_message(int read_bytes, int fd) {
    for (int i = 0, j = strlen(clients[fd].message); i < read_bytes; i++, j++) {
        clients[fd].message[j] = rbuf[i];
        if (clients[fd].message[j] == '\n') {
            clients[fd].message[j] = '\0';
            sprintf(wbuf, "client %d: %s\n", clients[fd].id, clients[fd].message);
            send_message(fd);
            bzero(&clients[fd].message, strlen(clients[fd].message));
            j = -1;
        }
    }
}

void register_client(int fd) {
    clients[fd].id = last_id++;
    FD_SET(fd, &fds);
    sprintf(wbuf, "server: client %d just arrived\n", clients[fd].id);
    send_message(fd);
}

void remove_client(int fd) {
    sprintf(wbuf, "server: client %d just left\n", clients[fd].id);
    send_message(fd);
    FD_CLR(fd, &fds);
    close(fd);
}
