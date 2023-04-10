/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:52:40 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 10:52:42 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(struct s_node **top_a, struct s_node **top_b)
{
	sa(top_a);
	sb(top_b);
}

void	rr(struct s_node **top_a, struct s_node **top_b)
{
	ra(top_a);
	rb(top_b);
}

void	rrr(struct s_node **top_a, struct s_node **top_b)
{
	rra(top_a);
	rrb(top_b);
}
