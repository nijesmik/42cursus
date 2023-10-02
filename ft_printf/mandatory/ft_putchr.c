/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:42:03 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 19:04:37 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_putchr_and_len_up(char c, int *len)
{
	if (write(1, &c, 1) < 0)
		return (0);
	*len += 1;
	return (1);
}
