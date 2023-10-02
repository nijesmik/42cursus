/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:04:20 by sejinkim          #+#    #+#             */
/*   Updated: 2023/10/02 15:08:07 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_len(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*_strjoin(char *str, char *buff, char *save, size_t len2)
{
	char	*ret;
	size_t	len1;

	len1 = get_len(str);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
		return (ft_free(str));
	_strlcpy(ret, str, len1 + 1);
	_strlcpy(ret + len1, buff, len2 + 1);
	free(str);
	_strlcpy(save, buff + len2, BUFFER_SIZE + 1 - len2);
	return (ret);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}
