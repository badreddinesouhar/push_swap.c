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

void	ss(t_node **top_a, t_node **top_b)
{
	sa(top_a, 0);
	sb(top_b, 0);
	ft_printf("%s\n", "ss");
}

void	rr(t_node **top_a, t_node **top_b)
{
	ra(top_a, 0);
	rb(top_b, 0);
	ft_printf("%s\n", "rr");
}

void	rrr(t_node **top_a, t_node **top_b)
{
	rra(top_a, 0);
	rrb(top_b, 0);
	ft_printf("%s\n", "rrr");
}
