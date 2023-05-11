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
SRC = main.c push_swap.c rules.c rules_b.c rules_rr.c sort.c check_avs.c
OBJ = $(SRC:.c=.o)
TARGET = push_swap
LIBFT = lib/libft.a

$(TARGET): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C lib all

clean:
	rm -f $(TARGET) $(OBJ)
	make -C lib clean

fclean: clean
	rm -f $(LIBFT)
	rm -rf lib/libft/*.o
	rm -rf lib/libft/libft.a

re: fclean all

.PHONY: all clean fclean re

