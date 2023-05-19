/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:48:03 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 15:54:56 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_stack(t_node **stack_a, t_node **stack_b, int *sorted,
		t_sort_info *info)
{
	while (stack_len(*stack_a))
	{
		info->top = (*stack_a)->data;
		info->index = get_index(info->top, sorted, info->size);
		if (info->index >= info->start && info->index <= info->end)
		{
			pb(stack_a, stack_b);
			info->start++;
			info->end++;
		}
		else if (info->index > info->end)
		{
			ra(stack_a, 1);
		}
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
			info->start++;
			info->end++;
		}
	}
}

void	final_hund_sort(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	max_index;

	while (stack_len(*stack_b))
	{
		max = max_value(*stack_b);
		max_index = find_index(*stack_b, max);
		if ((*stack_b)->data == max)
			pa(stack_b, stack_a);
		else if (max_index > (stack_len(*stack_b) / 2))
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
}
