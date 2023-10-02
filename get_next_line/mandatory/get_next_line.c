/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:43:17 by sejinkim          #+#    #+#             */
/*   Updated: 2023/10/02 15:08:14 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*duplicate_save(char *save, size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (!len)
	{
		str[0] = 0;
		return (str);
	}
	_strlcpy(str, save, len + 1);
	_strlcpy(save, save + len, BUFFER_SIZE + 1 - len);
	return (str);
}

char	*read_end(char *buff, char *str, ssize_t read_size)
{
	free(buff);
	if (read_size < 0 || !*str)
		return (ft_free(str));
	else
		return (str);
}

char	*make_str(int fd, char *str, char *save)
{
	char	*buff;
	ssize_t	read_size;
	size_t	len;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(str));
	len = 1;
	buff[len - 1] = 0;
	while (buff[len - 1] != '\n')
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size <= 0)
			return (read_end(buff, str, read_size));
		buff[read_size] = 0;
		len = get_len(buff);
		str = _strjoin(str, buff, save, len);
		if (!str)
			return (ft_free(buff));
	}
	free(buff);
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
	str = duplicate_save(save, len);
	if (!str)
		return (NULL);
	if (len > 0 && str[len - 1] == '\n')
		return (str);
	return (make_str(fd, str, save));
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