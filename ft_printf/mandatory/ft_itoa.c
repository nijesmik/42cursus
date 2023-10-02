/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:41:53 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/27 21:05:22 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(unsigned long long nb, int base)
{
	size_t	len;

	len = 0;
	if (!nb)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

static char	*make_str(unsigned long long num, size_t len, char c, int base)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[len] = 0;
	if (num == 0)
		return (str);
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
	return (str);
}

char	*ft_unsigned_itoa(va_list *ap, char c, t_flags *flags)
{
	unsigned long long		num;
	int						base;

	base = 16;
	if (c == 'x' || c == 'X')
	{
		num = va_arg(*ap, unsigned int);
		if (num == 0)
			flags->hex = 0;
	}
	else if (c == 'u')
	{
		num = va_arg(*ap, unsigned int);
		base = 10;
	}
	else
	{
		num = (unsigned long)va_arg(*ap, void *);
		flags->hex = 2;
	}
	flags->len = get_len(num, base);
	if (flags->precision == 0 && num == 0)
		flags->len = 0;
	return (make_str(num, flags->len, c, base));
}

char	*ft_itoa(int nb, t_flags *flags)
{
	long long		num;

	num = nb;
	if (num < 0)
	{
		flags->negative = 1;
		num *= -1;
	}
	if (num == 0)
		flags->hex = 0;
	flags->len = get_len(num, 10);
	if (flags->precision == 0 && num == 0)
		flags->len = 0;
	return (make_str(num, flags->len, 'd', 10));
}
