/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:41:08 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/28 14:10:18 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier_c(char c, t_flags *f)
{
	f->len = 1;
	check_extra_flag(f, f->specifier);
	if (print_width_flag(f, 0) < 0)
		return (PRINT_ERR);
	if (ft_putchr(f, c) < 0)
		return (PRINT_ERR);
	if (print_width_flag(f, 1) < 0)
		return (PRINT_ERR);
	return (f->ret);
}

int	ft_specifier_s(char *str, t_flags *f)
{
	f->len = ft_strlen(str);
	if (f->precision > -1 && (size_t)f->precision < f->len)
		f->len = f->precision;
	else if (f->precision > -1 && (size_t)f->precision > f->len)
		f->precision = f->len;
	check_extra_flag(f, f->specifier);
	if (print_width_flag(f, 0) < 0)
		return (PRINT_ERR);
	if (!str)
		ft_putstr(f, NULL_BRACKET, f->len);
	else
		ft_putstr(f, str, f->len);
	if (print_width_flag(f, 1) < 0)
		return (PRINT_ERR);
	return (f->ret);
}

int	ft_free(char *str)
{
	free(str);
	return (0);
}

int	ft_specifier_pdiux(char *str, t_flags *f)
{
	if (!str)
		return (PRINT_ERR);
	check_extra_flag(f, f->specifier);
	if (f->zero)
		print_extra_flag(f);
	if (print_width_flag(f, 0) < 0)
		return (PRINT_ERR + ft_free(str));
	if (!f->zero)
		print_extra_flag(f);
	if (print_precision_flag(f) < 0)
		return (PRINT_ERR + ft_free(str));
	ft_putstr(f, str, f->len);
	free(str);
	if (print_width_flag(f, 1) < 0)
		return (PRINT_ERR);
	return (f->ret);
}

int	ft_specifier(char c, va_list *ap, t_flags *f)
{
	f->specifier = c;
	if (c == 'c')
		return (ft_specifier_c(va_arg(*ap, int), f));
	else if (c == '%')
		return (ft_specifier_c('%', f));
	else if (c == 's')
		return (ft_specifier_s(va_arg(*ap, char *), f));
	else if (c == 'd' || c == 'i')
		return (ft_specifier_pdiux(ft_itoa(va_arg(*ap, int), f), f));
	else if (c == 'p' || c == 'u' || c == 'x' || c == 'X')
		return (ft_specifier_pdiux(ft_unsigned_itoa(ap, c, f), f));
	else if (!c)
		return (0);
	else
		return (ft_putchr(f, c));
}
