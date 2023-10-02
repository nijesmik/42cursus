/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:41:53 by sejinkim          #+#    #+#             */
/*   Updated: 2023/10/02 17:07:16 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(unsigned long long nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int	print_str(unsigned long long num, size_t len, char c, int base)
{
	char	*str;
	size_t	len2;

	len2 = len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	str[0] = '0';
	while (num > 0)
	{
		if (c == 'X')
			str[--len] = HEX_UPPERCASE[num % base];
		else if (c == 'x' || c == 'p')
			str[--len] = HEX_LOWERCASE[num % base];
		else
			str[--len] = num % base + '0';
		num /= base;
	}
	if (write(1, str, len2) < 0)
		len2 = 0;
	free(str);
	return (len2 > 0);
}

int	ft_itoa(va_list *ap)
{
	long long		num;
	size_t			len;
	size_t			neg;

	neg = 0;
	num = va_arg(*ap, int);
	if (num < 0)
	{
		if (write(1, "-", 1) < 0)
			return (PRINT_ERR);
		num *= -1;
		neg = 1;
	}
	len = get_len(num, 10);
	if (!print_str(num, len, 'd', 10))
		return (PRINT_ERR);
	return (len + neg);
}

int	ft_unsigned_itoa(va_list *ap, char c)
{
	unsigned long long		num;
	size_t					len;
	int						base;

	base = 16;
	if (c == 'u')
		base = 10;
	if (c == 'p')
		num = (unsigned long)va_arg(*ap, void *);
	else
		num = va_arg(*ap, unsigned int);
	len = get_len(num, base);
	if (c == 'p')
		if (write(1, "0x", 2) < 0)
			return (PRINT_ERR);
	if (!print_str(num, len, c, base))
		return (PRINT_ERR);
	return (len + (c == 'p') * 2);
}
