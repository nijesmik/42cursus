/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:26:59 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 17:58:42 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		check;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		while (*str != '%' && *str)
			if (!ft_putchr_and_len_up(*str++, &len))
				return (-1);
		if (*str == '%')
		{
			check = ft_conversion(++str, &ap);
			if (check < 0)
				return (-1);
			len += check;
		}
		if (*str)
			str++;
	}
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>

int main()
{
	int i = ft_printf("1:\001 2:\002 3:\007 4:\v 5:\010 6:\f 7:\r 8:\n");
	printf("\n<<%d>>\n\n",i);
	int j = printf("1:\001 2:\002 3:\007 4:\v 5:\010 6:\f 7:\r 8:\n");
	printf("\n<<%d>>",j);
}
*/