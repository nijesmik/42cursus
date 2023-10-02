/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:16:00 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 14:16:23 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion3(const char *str, va_list *ap)
{
	unsigned int	u;
	void			*p;

	if (*str == 'u')
	{
		u = va_arg(*ap, unsigned int);
		return (ft_putstr_and_free(ft_unsigned_itoa(u)));
	}
	else if (*str == 'x' || *str == 'X')
	{
		u = va_arg(*ap, unsigned int);
		if (*str == 'x')
			return (ft_putstr_and_free(ft_hex_itoa(u, LOWERCASE)));
		else
			return (ft_putstr_and_free(ft_hex_itoa(u, UPPERCASE)));
	}
	else if (*str == 'p')
	{
		p = va_arg(*ap, void *);
		return (ft_putstr_and_free(addr_to_str((unsigned long)p)));
	}
	return (0);
}

int	ft_conversion2(const char *str, va_list *ap)
{
	char	*s;
	int		d;

	if (*str == 's')
	{
		s = va_arg(*ap, char *);
		return (ft_putstr(s));
	}
	else if (*str == 'd' || *str == 'i')
	{
		d = va_arg(*ap, int);
		return (ft_putstr_and_free(ft_itoa(d)));
	}
	return (0);
}

int	ft_conversion(const char *str, va_list *ap)
{
	char	c;

	if (*str == '%')
		return (ft_putchr('%'));
	else if (*str == 'c')
	{
		c = va_arg(*ap, int);
		return (ft_putchr(c));
	}
	else if (*str == 's' || *str == 'd' || *str == 'i')
		return (ft_conversion2(str, ap));
	else if (*str == 'x' || *str == 'X' || *str == 'u' || *str == 'p')
		return (ft_conversion3(str, ap));
	else if (!str)
		return (0);
	else
		return (ft_putchr(*str));
}
