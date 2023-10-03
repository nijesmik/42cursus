/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:43:17 by sejinkim          #+#    #+#             */
/*   Updated: 2023/10/03 12:05:46 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_end(char *str, ssize_t read_size)
{
	if (read_size < 0 || !*str)
		return (ft_free(str));
	else
		return (str);
}

char	*make_str(int fd, char *str, char *save, size_t savelen)
{
	ssize_t	read_size;
	size_t	strlen;

	strlen = savelen;
	while (!*str || str[strlen - 1] != '\n')
	{
		read_size = read(fd, save, BUFFER_SIZE);
		if (read_size <= 0)
			return (read_end(str, read_size));
		save[read_size] = 0;
		savelen = get_len(save);
		str = _strjoin(str, save, strlen, savelen);
		if (!str)
			return (NULL);
		strlen += savelen;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*str;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = get_len(save);
	str = _strjoin(NULL, save, 0, len);
	if (!str)
		return (NULL);
	return (make_str(fd, str, save, len));
}
/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd2 = open("a", O_RDONLY);
	char *str = get_next_line(fd2);
	printf("return : %s\n",str);
	char *str2 = get_next_line(fd2);
	printf("return : %s\n",str2);
	char *str3 = get_next_line(fd2);
	printf("return : %s\n",str3);
	char *str4 = get_next_line(fd2);
	printf("return : %s\n",str4);
	char *str5 = get_next_line(fd2);
	printf("return : %s\n",str5);
	char *str6 = get_next_line(fd2);
	printf("return : %s\n",str6);
}
*/