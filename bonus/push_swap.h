/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:29 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 18:34:13 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node	t_node;

struct					s_node
{
	int					data;
	t_node				*next;
};

typedef struct s_program
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		j;
	char	**args;
	char	**nums;
}				t_program;

void					push(t_node **top, int value);
void					sa(t_node **top);
void					pa(t_node **src, t_node **dst);
void					ra(t_node **top);
void					rra(t_node **top);
void					sb(t_node **top_b);
void					pb(t_node **top_a, t_node **top_b);
void					rb(t_node **top_b);
void					rrb(t_node **top_b);
void					rrr(t_node **top_a, t_node **top_b);
void					rr(t_node **top_a, t_node **top_b);
void					ss(t_node **top_a, t_node **top_b);
char					**check_args(char **argv);
void					error(void);
char					**no_errors(char **args);
int						ft_same(const char *s1, const char *s2);
void					free_arr(char **arr);
void					free_list(t_node **stack);
int						is_sorted(t_node *stack);
int						is_valid_input(char **av_split);
int						ft_isdigit_str(char *str);
void					sort(t_node **stack_a, t_node **stack_b,
							int *sorted_arr);
int						stack_len(t_node *stack);

#endif
