/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:29:48 by sejinkim          #+#    #+#             */
/*   Updated: 2023/10/02 16:59:54 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define HEX_LOWERCASE "0123456789abcdef"
# define HEX_UPPERCASE "0123456789ABCDEF"
# define PRINT_ERR -1

int		ft_printf(const char *str, ...);
int		ft_conversion(const char **str, va_list *ap);
int		ft_putstr(char *str);
int		ft_itoa(va_list *ap);
int		ft_unsigned_itoa(va_list *ap, char c);
int		ft_putchr(char c);

#endif