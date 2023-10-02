/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:43:17 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/24 10:38:52 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	move_to_save(char *save, char *buff, int idx)
{
	int	i;

	i = 0;
	while (buff[idx + i])
	{
		save[i] = buff[idx + i];
		i++;
	}
	save[i] = 0;
}

char	*duplicate_save(char *save)
{
	int		len;
	char	*str;

	len = get_len(save);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, save, len + 1);
	move_to_save(save, save, len);
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

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(str));
	while (!*str || str[get_len(str) - 1] != '\n')
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size <= 0)
			return (read_end(buff, str, read_size));
		buff[read_size] = 0;
		str = ft_strjoin(str, buff, save);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = duplicate_save(save);
	if (!str)
		return (NULL);
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