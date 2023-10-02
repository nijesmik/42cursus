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

#include "ft_printf_bonus.h"

t_flags	*flag_init(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->err = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->len = 0;
	flags->ret = 0;
	flags->zero = 0;
	flags->negative = 0;
	flags->minus = 0;
	flags->hex = 0;
	flags->plus = 0;
	flags->space = 0;
	return (flags);
}

int	check_flags(char c)
{
	return (c == '0' || c == '-' || c == '#' || c == '+' || c == ' ');
}

void	flag_on(char c, t_flags **flags)
{
	if (c == '0' && (*flags)->minus == 0)
		(*flags)->zero = 1;
	if (c == '-')
	{
		(*flags)->minus = 1;
		(*flags)->zero = 0;
	}
	if (c == '.')
	{
		(*flags)->zero = 0;
		(*flags)->precision = 0;
	}
	if (c == '#')
		(*flags)->hex = 2;
	if (c == '+')
		(*flags)->plus = 1;
	if (c == ' ')
		(*flags)->space = 1;
}

int	free_flags(t_flags *flags)
{
	free(flags);
	return (0);
}

int	ft_conversion(const char **str, va_list *ap)
{
	int		len;
	t_flags	*flags;

	flags = flag_init();
	if (!flags)
		return (PRINT_ERR);
	while (check_flags(**str))
		flag_on(*((*str)++), &flags);
	while ('0' <= **str && **str <= '9')
		flags->width = flags->width * 10 + *((*str)++) - '0';
	if (**str == '.')
		flag_on(*((*str)++), &flags);
	while ('0' <= **str && **str <= '9')
		flags->precision = flags->precision * 10 + *((*str)++) - '0';
	len = ft_specifier(**str, ap, flags);
	if (**str)
		(*str)++;
	if (flags->err || len < 0)
		return (PRINT_ERR + free_flags(flags));
	return (len + free_flags(flags));
}
