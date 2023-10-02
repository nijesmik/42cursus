/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:18:22 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 19:04:33 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		if (write(1, NULL_BRACKET, 6) < 0)
			return (-1);
		len = 6;
	}
	else
		while (str[len])
			if (!ft_putchr_and_len_up(str[len], &len))
				return (-1);
	return (len);
}

int	ft_putstr_and_free(char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
	{
		if (!ft_putchr_and_len_up(str[len], &len))
		{
			free(str);
			return (-1);
		}
	}
	free(str);
	return (len);
}

size_t	get_len(unsigned long addr)
{
	size_t	len;

	if (!addr)
		return (3);
	len = 2;
	while (addr > 0)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

char	*addr_to_str(unsigned long addr)
{
	size_t	len;
	char	*str;

	len = get_len(addr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[len] = 0;
	if (!addr)
		str[2] = '0';
	while (addr > 0)
	{
		str[--len] = HEX_LOWERCASE[addr % 16];
		addr /= 16;
	}
	return (str);
}
