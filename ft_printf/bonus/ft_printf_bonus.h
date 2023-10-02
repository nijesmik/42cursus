/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:29:48 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/28 14:19:33 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define NULL_BRACKET "(null)"
# define HEX_LOWERCASE "0123456789abcdef"
# define HEX_UPPERCASE "0123456789ABCDEF"
# define PRINT_ERR -1

typedef struct s_flags
{
	char	specifier;
	int		err;
	size_t	width;
	size_t	len;
	int		precision;
	int		ret;
	int		zero;
	int		negative;
	int		minus;
	int		hex;
	int		plus;
	int		space;
}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_conversion(const char **str, va_list *ap);
int		ft_specifier(char c, va_list *ap, t_flags *flags);
char	*ft_itoa(int nb, t_flags *flags);
char	*ft_unsigned_itoa(va_list *ap, char c, t_flags *flags);
int		print_width_flag(t_flags *flags, int minus);
int		print_precision_flag(t_flags *f);
void	print_extra_flag(t_flags *f);
void	check_extra_flag(t_flags *f, char c);
int		ft_putchr(t_flags *flags, char c);
void	ft_putstr(t_flags *flags, char *str, size_t len);
size_t	ft_strlen(const char *str);

#endif