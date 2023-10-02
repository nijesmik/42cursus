/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:29:48 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 19:14:14 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define UPPERCASE 1
# define LOWERCASE 0
# define NULL_BRACKET "(null)"
# define HEX_LOWERCASE "0123456789abcdef"
# define HEX_UPPERCASE "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		ft_conversion(const char *str, va_list *ap);
int		ft_putstr(char *str);
int		ft_putstr_and_free(char *str);
char	*ft_itoa(int nb);
char	*ft_unsigned_itoa(unsigned int nb);
char	*ft_hex_itoa(unsigned int nb, int uppercase);
int		ft_putchr(char c);
int		ft_putchr_and_len_up(char c, int *len);
char	*addr_to_str(unsigned long addr);

#endif