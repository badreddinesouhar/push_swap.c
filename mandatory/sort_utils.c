/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:26:06 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/11 23:26:32 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int		length;
	t_node	*current;

	length = 0;
	current = stack;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return (length);
}

int	min_val(t_node **stack)
{
	int		*min;
	t_node	*tmp;

	if (*stack == NULL)
		return (-1);
	min = &(*stack)->data;
	tmp = (*stack)->next;
	while (tmp != NULL)
	{
		if (tmp->data < *min)
			min = &tmp->data;
		tmp = tmp->next;
	}
	return (*min);
}

int	min_idx(t_node **stack)
{
	size_t	min_index;
	t_node	*tmp;

	min_index = 0;
	if (*stack == NULL)
		return (-1);
	tmp = (*stack)->next;
	while (tmp != NULL)
	{
		if (tmp->data < (*stack)->data)
			min_index++;
		tmp = tmp->next;
	}
	return ((int)min_index);
}

void	sort(t_node **stack_a, t_node **stack_b, int *sorted_arr)
{
	int	len;

	len = stack_len(*stack_a);
	if (len == 2)
		sa(stack_a, 1);
	else if (len == 3)
		sort_three_numbers(stack_a);
	else if (len <= 5)
		sort_five_numbers(stack_a, stack_b);
	else if (len <= 100)
		sort_hun_numbers(stack_a, stack_b, sorted_arr);
	else if (len <= 500)
		sort_fivehun_numbers(stack_a, stack_b, sorted_arr);
}
