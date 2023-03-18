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

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct					s_node
{
	int					data;
	struct s_node		*next;
};

extern struct s_node	*g_top_a;
extern struct s_node	*g_top_b;

void					push_a(int value);
void					push_b(int value);
void					sa(void);
void					display_a(void);
void					display_b(void);
void					sb(void);
void					ss(void);
void					pa(void);
void					pb(void);
void					ra(void);
void					rb(void);
void					rr(void);
void					rra(void);
void					rrb(void);
void					rrr(void);
void					sort_three_numbers(void);

#endif
