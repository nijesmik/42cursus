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

int	ft_specifier(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchr(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(ap));
	else if (c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (ft_unsigned_itoa(ap, c));
	else if (!c)
		return (0);
	else
		return (ft_putchr(c));
}

int	ft_conversion(const char **str, va_list *ap)
{
	int	len;

	len = ft_specifier(**str, ap);
	if (**str)
		(*str)++;
	return (len);
}
