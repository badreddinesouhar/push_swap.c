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
		sa(top);
	else if (a > b && b > c)
	{
		sa(top);
		rra(top);
	}
	else if (a > b && b < c && a > c)
		ra(top);
	else if (a < b && b > c && c > a)
	{
		sa(top);
		ra(top);
	}
	else if (a < b && b > c && a > c)
		rra(top);
}

void	sort_five_numbers(t_node **stack_a, t_node **stack_b)
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
}

void	sort_hun_numbers(t_node **stack_a, t_node **stack_b, int *sorted)
{
	int	start;
	int	end;
	int	top;
	int	index;
	int	size;

	start = 0;
	end = 19;
	size = stack_len(*stack_a);
	while (stack_len(*stack_a))
	{
		top = (*stack_a)->data;
		index = get_index(top, sorted, size);
		if (index >= start && index <= end)
		{
			pb(stack_a, stack_b);
			start++;
			end++;
		}
		else if (index > end)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			start++;
			end++;
		}
	}
	final_hund_sort(stack_a, stack_b);
}

// void	sort_hun_numbers(t_node **stack_a, t_node **stack_b, int *sorted)
// {
// 	int	size;
// 	int	start;
// 	int	end;
// 	int	top;
// 	int	index;

// 	size = stack_len(*stack_a);
// 	start = 0;
// 	end = 19;
// 	while (stack_len(*stack_a))
// 	{
// 		top = (*stack_a)->data;
// 		index = get_index(top, sorted, size);
// 		if (is_within_range(index, start, end))
// 			move_to_stack_b(stack_a, stack_b, start, end);
// 		else
// 			move_to_stack_b_and_rotate(stack_a, stack_b, start, end);
// 	}
// 	final_hund_sort(stack_a, stack_b);
// }

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
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

void	sort_fivehun_numbers(t_node **stack_a, t_node **stack_b, int *sorted)
{
	int	start;
	int	end;
	int	top;
	int	index;
	int	size;

	size = stack_len(*stack_a);
	start = 0;
	end = 35;
	while (stack_len(*stack_a))
	{
		top = (*stack_a)->data;
		index = get_index(top, sorted, size);
		if (index >= start && index <= end)
		{
			pb(stack_a, stack_b);
			start++;
			end++;
		}
		else if (index > end)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			start++;
			end++;
		}
	}
	final_hund_sort(stack_a, stack_b);
}

// void	sort_fivehun_numbers(t_node **stack_a, t_node **stack_b, int *sorted)
// {
// 	int	size;
// 	int	start;
// 	int	end;
// 	int	top;
// 	int	index;

// 	size = stack_len(*stack_a);
// 	start = 0;
// 	end = 35;
// 	while (stack_len(*stack_a))
// 	{
// 		top = (*stack_a)->data;
// 		index = get_index(top, sorted, size);
// 		if (is_within_range(index, start, end))
// 			move_to_stack_b(stack_a, stack_b, start, end);
// 		else
// 			move_to_stack_b_and_rotate(stack_a, stack_b, start, end);
// 	}
// 	final_hund_sort(stack_a, stack_b);
// }

// void	ft_rannge(t_node **stack_a, t_node **stack_b, int *sorted, )