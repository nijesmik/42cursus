/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:04:20 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/24 10:33:48 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		i++;
	}
	if (size > 0)
		*dest = 0;
	while (*src++)
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buff, char *save)
{
	char	*ret;
	int		len1;
	int		len2;

	len1 = get_len(str);
	len2 = get_len(buff);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
		return (ft_free(str));
	ft_strlcpy(ret, str, len1 + 1);
	ft_strlcpy(ret + len1, buff, len2 + 1);
	free(str);
	move_to_save(save, buff, len2);
	return (ret);
}

char	*ft_free(char *str)
{
	free(str);
	return (0);
}
