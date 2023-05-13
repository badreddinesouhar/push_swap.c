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
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct				s_node
{
	int				data;
	struct s_node	*next;
};

void				push(struct s_node **top, int value);
int					pop(struct s_node **top);
void				display(struct s_node *top);
void				sa(struct s_node **top);
void				pa(struct s_node **src, struct s_node **dst);
void				ra(struct s_node **top);
void				rra(struct s_node **top);
void				print_stack(struct s_node *top);
void				sb(struct s_node **top_b);
void				pb(struct s_node **top_a, struct s_node **top_b);
void				rb(struct s_node **top_b);
void				rrb(struct s_node **top_b);
void				rrr(struct s_node **top_a, struct s_node **top_b);
void				rr(struct s_node **top_a, struct s_node **top_b);
void				ss(struct s_node **top_a, struct s_node **top_b);
void				sort_three_numbers(struct s_node **top);
char				**check_args(char **argv);
void				error(void);
char				**no_errors(char **args);
int					ft_same(const char *s1, const char *s2);
void				free_arr(char **arr);
void				free_list(struct s_node **stack);
int					is_sorted(struct s_node *stack);
int					is_valid_input(char **av_split);
int					ft_isdigit_str(char *str);
int					*sorting_arr(char **argv, int size);
void				sort(struct s_node **stack_a, struct s_node **stack_b,
						int *sorted_arr);
int					stack_len(struct s_node *stack);
int					min_val(struct s_node **stack);
int					min_idx(struct s_node **stack);
void	sort_five_numbers(struct s_node **stack_a,
						struct s_node **stack_b);
void	final_hund_sort(struct s_node **stack_a,
						struct s_node **stack_b);
void	sort_hun_numbers(struct s_node **stack_a,
						struct s_node **stack_b,
						int *sorted);
void	sort_fivehun_numbers(struct s_node **stack_a, struct s_node **stack_b,
		int *sorted);

#endif
