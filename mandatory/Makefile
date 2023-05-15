# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 09:29:12 by bsouhar           #+#    #+#              #
#    Updated: 2023/03/13 09:29:16 by bsouhar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 
 CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c push_swap.c rules.c rules_b.c rules_rr.c sort.c check_avs.c quicksort.c \
	sort_utils.c
OBJ = $(SRC:.c=.o)
TARGET = push_swap
LIBFT = lib/libft.a
PRINTF = ft_printf

$(TARGET): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBFT) -L ft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C lib all
	make -C ft_printf all

clean:
	rm -f $(TARGET) $(OBJ)
	make -C lib clean
	make -C ft_printf clean

fclean: clean
	rm -f $(LIBFT)
	rm -rf lib/libft/*.o
	rm -rf lib/libft/libft.a
	rm -f ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
