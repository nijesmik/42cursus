/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:21:39 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 16:04:44 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(long long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

char	*make_hex_str(long long num, size_t len, int uppercase)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		if (uppercase)
			str[--len] = HEX_UPPERCASE[num % 16];
		else
			str[--len] = HEX_LOWERCASE[num % 16];
		num /= 16;
	}
	return (str);
}

char	*ft_hex_itoa(unsigned int nb, int uppercase)
{
	long long	num;
	size_t		len;

	num = (long long) nb;
	len = get_len(num);
	return (make_hex_str(num, len, uppercase));
}
