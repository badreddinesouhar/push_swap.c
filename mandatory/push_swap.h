/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:29 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 09:28:32 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct	s_node t_node;

struct				s_node
{
	int				data;
	t_node	*next;
};

void				push(t_node **top, int value);
int					pop(t_node **top);
void				sa(t_node **top);
void				pa(t_node **src, t_node **dst);
void				ra(t_node **top);
void				rra(t_node **top);
void				print_stack(t_node *top);
void				sb(t_node **top_b);
void				pb(t_node **top_a, t_node **top_b);
void				rb(t_node **top_b);
void				rrb(t_node **top_b);
void				rrr(t_node **top_a, t_node **top_b);
void				rr(t_node **top_a, t_node **top_b);
void				ss(t_node **top_a, t_node **top_b);
void				sort_three_numbers(t_node **top);
char				**check_args(char **argv);
void				error(void);
char				**no_errors(char **args);
int					ft_same(const char *s1, const char *s2);
void				free_arr(char **arr);
void				free_list(t_node **stack);
int					is_sorted(t_node *stack);
int					is_valid_input(char **av_split);
int					ft_isdigit_str(char *str);
int					*sorting_arr(char **argv, int size);
void				sort(t_node **stack_a, t_node **stack_b,
						int *sorted_arr);
int					stack_len(t_node *stack);
int					min_val(t_node **stack);
int					min_idx(t_node **stack);
void	sort_five_numbers(t_node **stack_a,
						t_node **stack_b);
void	final_hund_sort(t_node **stack_a,
						t_node **stack_b);
void	sort_hun_numbers(t_node **stack_a,
						t_node **stack_b,
						int *sorted);
void	sort_fivehun_numbers(t_node **stack_a, t_node **stack_b,
		int *sorted);

#endif
