/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:26:59 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/28 13:57:02 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		total_len;
	int		conv_len;

	va_start(ap, str);
	total_len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			conv_len = ft_conversion(&str, &ap);
			if (conv_len < 0)
				return (PRINT_ERR);
			total_len += conv_len;
		}
		else
		{
			if (write(1, str++, 1) < 0)
				return (PRINT_ERR);
			total_len++;
		}
	}
	va_end(ap);
	return (total_len);
}

// #include <stdio.h>
// #include <limits.h>

// int main()
// {
// 	int i = ft_printf("%5c, %5c, %5c", '5', 'x', '\n');
// 	printf("\n<<%d>>\n\n",i);
// 	int j = printf("%5c, %5c, %5c", '5', 'x', '\n');
// 	printf("\n<<%d>>",j);
// }
