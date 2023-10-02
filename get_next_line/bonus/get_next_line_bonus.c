/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:43:17 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/24 10:38:39 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	move_to_save(t_list *node, char *buff, int idx)
{
	int	i;

	i = 0;
	while (buff[idx + i])
	{
		node->save[i] = buff[idx + i];
		i++;
	}
	node->save[i] = 0;
}

char	*duplicate_save(t_list *node)
{
	int		len;
	char	*str;

	len = get_len(node->save);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, node->save, len + 1);
	move_to_save(node, node->save, len);
	return (str);
}

char	*read_end(t_list *node, t_list **list, char *str, char *buff)
{
	int		size;

	size = node->read_size;
	ft_free(list, node, buff);
	if (size < 0 || !*str)
	{
		free(str);
		return (NULL);
	}
	else
		return (str);
}

char	*make_str(char *str, t_list *node, t_list **list)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(list, node, str));
	while (!*str || str[get_len(str) - 1] != '\n')
	{
		node->read_size = read(node->fd, buff, BUFFER_SIZE);
		if (node->read_size <= 0)
			return (read_end(node, list, str, buff));
		buff[node->read_size] = 0;
		str = ft_strjoin(str, buff, node);
		if (!str)
			return (ft_free(list, node, buff));
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;
	t_list			*node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_fd_node(&list, fd);
	if (!node)
		return (NULL);
	str = duplicate_save(node);
	if (!str)
		return (ft_free(&list, node, NULL));
	return (make_str(str, node, &list));
}
/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("a", O_RDONLY);
	int fd2 = open("b", O_RDONLY);

	char *str = get_next_line(fd1);
	printf("return(fd1) : %s\n",str);
	char *str2 = get_next_line(fd2);
	printf("return(fd2) : %s\n",str2);
	char *str3 = get_next_line(fd1);
	printf("return(fd1) : %s\n",str3);
	char *str4 = get_next_line(fd2);
	printf("return(fd2) : %s\n",str4);
	char *str5 = get_next_line(fd1);
	printf("return(fd1) : %s\n",str5);
	char *str6 = get_next_line(fd2);
	printf("return(fd2) : %s\n",str6);
}
*/