/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:01:13 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/10 10:22:35 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(struct s_node **top)
{
	int	a;
	int	b;
	int	c;

	if (*top == NULL || (*top)->next == NULL || (*top)->next->next == NULL)
	{
		return ;
	}
	a = (*top)->data;
	b = (*top)->next->data;
	c = (*top)->next->next->data;
	if (a > b && b < c && c > a)
	{
		sa(top);
	}
	else if (a > b && b > c)
	{
		sa(top);
		rra(top);
	}
	else if (a > b && b < c && a > c)
	{
		ra(top);
	}
	else if (a < b && b > c && c > a)
	{
		sa(top);
		ra(top);
	}
	else if (a < b && b > c && a > c)
	{
		rra(top);
	}
}
void	sort_five_numbers(struct s_node **stack_a, struct s_node **stack_b)
{
	int	min_index;
	int	min;
	int	middle;

	while (stack_len(*stack_a) > 3)
	{
		min = min_val(stack_a);
		min_index = min_idx(stack_a);
		middle = stack_len(*stack_a) / 2;
		while ((*stack_a)->data != min)
		{
			if (min_index >= middle)
				rra(stack_a);
			else if (min_index <= middle)
				ra(stack_a);
		}
		if ((*stack_a)->data == min)
			pb(stack_a, stack_b);
	}
	if (is_sorted(*stack_a) <= 3)
		sort_three_numbers(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	display(*stack_a);
}

void sort_hun_numbers(struct s_node **stack_a, struct s_node **stack_b, int *sorted)
{
	int start;
	int end;

	start = 0;
	end = 15;
	while (stack_len(*stack_a))
	{
		if ()
	}
}