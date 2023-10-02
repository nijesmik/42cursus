# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 11:07:07 by sejinkim          #+#    #+#              #
#    Updated: 2023/10/02 14:11:25 by sejinkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS_BONUS = ./bonus/ft_conversion_bonus.c ./bonus/ft_itoa_bonus.c \
			./bonus/ft_print_flag_bonus.c ./bonus/ft_printf_bonus.c \
			./bonus/ft_putstr_bonus.c ./bonus/ft_specifier_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

SRCS_DIR = ./mandatory/
SRCS = \
	$(SRCS_DIR)ft_conversion.c \
	$(SRCS_DIR)ft_itoa.c \
	$(SRCS_DIR)ft_print_flag.c \
	$(SRCS_DIR)ft_printf.c \
	$(SRCS_DIR)ft_putstr.c \
	$(SRCS_DIR)ft_specifier.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : make_mandatory

bonus : make_bonus

make_bonus : $(OBJS_BONUS)
	@rm -f make_mandatory make_bonus $(NAME)
	ar rc $(NAME) $^
	@touch $@

make_mandatory : $(OBJS)
	@rm -f make_mandatory make_bonus $(NAME)
	ar rc $(NAME) $^
	@touch $@

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ 

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : 
	make clean
	@rm -f make_mandatory make_bonus
	rm -f $(NAME)

re :
	make fclean 
	make all

.PHONY : all clean fclean re bonus