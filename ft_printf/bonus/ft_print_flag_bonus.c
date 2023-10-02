/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:18:22 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/28 14:20:39 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_flag(size_t len, char c, t_flags *f)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * len);
	if (!tmp)
		return (PRINT_ERR);
	i = 0;
	while (i < len)
		tmp[i++] = c;
	ft_putstr(f, tmp, len);
	free(tmp);
	return (1);
}

int	print_width_flag(t_flags *f, int minus)
{
	char	c;
	size_t	tmp;

	if (f->err)
		return (PRINT_ERR);
	if (f->precision > -1 && (size_t)f->precision > f->len)
		tmp = f->precision;
	else
		tmp = f->len;
	tmp += f->negative + f->hex + f->plus + f->space;
	f->ret = (f->width > tmp) * (f->width - tmp) + tmp;
	c = '0' * (f->zero == 1) + ' ' * (f->zero == 0);
	if (f->minus == minus && f->width > tmp)
	{
		if (print_flag(f->width - tmp, c, f) < 0)
			return (PRINT_ERR);
	}
	return (1);
}

int	print_precision_flag(t_flags *f)
{
	size_t	cnt;

	if (f->err)
		return (PRINT_ERR);
	if (f->precision < 0)
		return (0);
	if ((size_t)f->precision > f->len)
	{
		cnt = (size_t)f->precision - f->len;
		if (print_flag(cnt, '0', f) < 0)
			return (PRINT_ERR);
	}
	return (1);
}

void	print_extra_flag(t_flags *f)
{
	if (f->err)
		return ;
	if (f->negative)
		ft_putchr(f, '-');
	else if (f->plus)
		ft_putchr(f, '+');
	else if (f->space)
		ft_putchr(f, ' ');
	else if (f->hex)
	{
		if (f->specifier == 'x' || f->specifier == 'p')
			ft_putstr(f, "0x", 2);
		else if (f->specifier == 'X')
			ft_putstr(f, "0X", 2);
	}
}

void	check_extra_flag(t_flags *f, char c)
{
	if (!((c == 'i' || c == 'd') && (f->negative == 0)))
	{
		f->plus = 0;
		f->space = 0;
	}
}
