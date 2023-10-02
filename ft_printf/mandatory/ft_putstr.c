/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:18:22 by sejinkim          #+#    #+#             */
/*   Updated: 2023/10/02 17:09:04 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (6);
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr(char *str)
{
	size_t	len;

	len = _strlen(str);
	if (!str)
	{
		if (write(1, "(null)", len) < 0)
			return (PRINT_ERR);
	}
	else
		if (write(1, str, len) < 0)
			return (PRINT_ERR);
	return (len);
}

int	ft_putchr(char c)
{
	if (write(1, &c, 1) < 0)
		return (PRINT_ERR);
	return (1);
}
