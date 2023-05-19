# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 09:29:12 by bsouhar           #+#    #+#              #
#    Updated: 2023/05/19 19:05:51 by bsouhar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = mandatory/main.c mandatory/push_swap.c mandatory/rules.c mandatory/rules_b.c mandatory/rules_rr.c mandatory/sort.c mandatory/check_avs.c mandatory/quicksort.c \
	mandatory/sort_utils.c mandatory/sort_utils2.c mandatory/sort_big.c mandatory/check_avs2.c
	
SRCB = bonus/main.c bonus/push_swap.c bonus/rules.c bonus/rules_b.c bonus/rules_rr.c bonus/check_avs.c bonus/check_avs2.c bonus/get_next_line.c bonus/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
TARGET = push_swap
BONUS = checker
LIBFT = mandatory/lib/libft.a
LIBFTB = bonus/lib/libft.a
PRINTF = mandatory/ft_printf


all: 	$(TARGET)
bonus : $(BONUS)

$(TARGET): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBFT) -L mandatory/ft_printf -lftprintf

$(BONUS): $(OBJB) $(LIBFTB)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJB) $(LIBFTB)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C mandatory/lib
	make -C mandatory/ft_printf
	
$(LIBFTB):
	make -C bonus/lib
	
clean:
	make clean -C mandatory/lib
	make clean -C  mandatory/ft_printf
	rm -f $(OBJ)

cleanb:
	make clean -C bonus/lib
	rm -f $(OBJB)

fclean: clean
	make fclean -C mandatory/lib
	make fclean -C  mandatory/ft_printf
	rm -f $(TARGET)

fcleanb: cleanb
	make fclean -C bonus/lib
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus cleanb fclean

