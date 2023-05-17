# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 21:17:58 by bsouhar           #+#    #+#              #
#    Updated: 2022/10/28 19:42:33 by bsouhar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror  

NAME = libftprintf.a

SRCS =  ft_printf.c\
		ft_putchar.c\
		ft_puthex.c\
		ft_putnbr.c\
		ft_putunnbr.c\
		ft_putstr.c\
		ft_putpointer.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^


%.o : %.c
	$(CC) $(CFLAGS) -c $^
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
