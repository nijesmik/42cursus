/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:42:03 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/28 14:16:01 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(t_flags *flags, char c)
{
	if (flags->err)
		return (PRINT_ERR);
	if (write(1, &c, 1) < 0)
	{
		flags->err = 1;
		return (PRINT_ERR);
	}
	return (1);
}

void	ft_putstr(t_flags *flags, char *str, size_t len)
{
	if (flags->err)
		return ;
	if (write(1, str, len) < 0)
		flags->err = 1;
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (6);
	while (str[len])
		len++;
	return (len);
}
