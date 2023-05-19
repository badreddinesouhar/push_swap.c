/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:01:13 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 17:18:06 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_node **top)
{
	int	a;
	int	b;
	int	c;

	if (*top == NULL || (*top)->next == NULL || (*top)->next->next == NULL)
		return ;
	a = (*top)->data;
	b = (*top)->next->data;
	c = (*top)->next->next->data;
	if (a > b && b < c && c > a)
		sa(top, 1);
	else if (a > b && b > c)
	{
		sa(top, 1);
		rra(top, 1);
	}
	else if (a > b && b < c && a > c)
		ra(top, 1);
	else if (a < b && b > c && c > a)
	{
		sa(top, 1);
		ra(top, 1);
	}
	else if (a < b && b > c && a > c)
		rra(top, 1);
}

void	sort_five_numbers(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	min_index;

	while (stack_len(*stack_a) != 3)
	{
		min = min_val(stack_a);
		min_index = find_index(*stack_a, min);
		if ((*stack_a)->data == min)
			pb(stack_a, stack_b);
		else if (min_index > stack_len(*stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	if (!is_sorted(*stack_a))
		sort_three_numbers(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	sort_hun_numbers(t_node **stack_a, t_node **stack_b, int *sorted)
{
	t_sort_info	info;

	info.start = 0;
	info.end = 19;
	info.size = stack_len(*stack_a);
	process_stack(stack_a, stack_b, sorted, &info);
	final_hund_sort(stack_a, stack_b);
}

void	sort_fivehun_numbers(t_node **stack_a, t_node **stack_b, int *sorted)
{
	t_sort_info	info;

	info.start = 0;
	info.end = 35;
	info.size = stack_len(*stack_a);
	process_stack(stack_a, stack_b, sorted, &info);
	final_hund_sort(stack_a, stack_b);
}
