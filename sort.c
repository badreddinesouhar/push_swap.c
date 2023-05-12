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

// int	get_index(int top, int *arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i] != 0)
// 	{
// 		if (arr[i] == top)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// int	max_value(struct s_node **stack_b)
// {
// 	int	max;

// 	max = INT_MIN;
// 	while (stack_b != NULL)
// 	{
// 		if (stack_b->data > max)
// 		{
// 			max = stack_b->data;
// 		}
// 		top = stack_b->next;
// 	}
// 	return (max);
// }
// int	find_index(struct s_node **stack, int value)
// {
// 	int	index;

// 	index = 0;
// 	while (stack != NULL)
// 	{
// 		if (stack->data == value)
// 		{
// 			return (index);
// 		}
// 		stack = stack->next;
// 		index++;
// 	}
// 	return (-1);
// }
// void	sort_hun_numbers(struct s_node **stack_a, struct s_node **stack_b,
// 		int *sorted)
// {
// 	int	start;
// 	int	end;
// 	int	top;
// 	int	index;

// 	top = (*stack_a)->data;
// 	start = 0;
// 	end = 15;
// 	index = get_index(top, sorted);
// 	while (stack_len(*stack_a))
// 	{
// 		if (index >= start && index <= end)
// 		{
// 			pb(stack_a, stack_b);
// 			start++;
// 			end++;
// 		}
// 		else if (index > end)
// 			ra(stack_a);
// 		else
// 		{
// 			pb(stack_a, stack_b);
// 			rb(stack_b);
// 			start++;
// 			end++;
// 		}
// 	}
// 	final_hund_sort(stack_a, stack_b);
// }

// void	final_hund_sort(struct s_node **stack_a, str s_node **stack_b)
// {
// 	int len;
// 	int max;
// 	int max_index;

// 	len = stack_len(*stack_b);
// 	while (stack_len(*stack_b))
// 	{
// 		max = max_value(*stack_b);
// 		max_index = find_index(stack_b, max);
// 		if ((*stack_a)->data == max)
// 			pa(stack_b, stack_a);
// 		else if (max_index > (stack_len(*stack_b) / 2))
// 			rrb(stack_b);
// 		else
// 			rb(stack_b);
// 	}
// }

int get_index(int top, int *arr)
{
    int i;
    int last_index = -1;

    i = 0;
    while (arr[i] != 0)
    {
        if (arr[i] == top)
            last_index = i;
        i++;
    }
    return last_index;
}


int	max_value(struct s_node *stack_b)
{
	int	max;

	max = INT_MIN;
	while (stack_b != NULL)
	{
		if (stack_b->data > max)
		{
			max = stack_b->data;
		}
		stack_b = stack_b->next;
	}
	return (max);
}

// int	find_index(struct s_node *stack, int value)
// {
// 	int	index;

// 	index = 0;
// 	while (stack != NULL)
// 	{
// 		if (stack->data == value)
// 		{
// 			return (index);
// 		}
// 		stack = stack->next;
// 		index++;
// 	}
// 	return (-1);
// }

struct s_node *find_node(struct s_node *stack, int value)
{
    while (stack != NULL)
    {
        if (stack->data == value)
        {
            return stack;
        }
        stack = stack->next;
    }
    return NULL;
}

int find_index(struct s_node *stack, int value)
{
    struct s_node *node = find_node(stack, value);
    if (node == NULL) {
        return -1;
    }
    int index = 0;
    while (stack != node)
    {
        stack = stack->next;
        index++;
    }
    return index;
}

void	sort_hun_numbers(struct s_node **stack_a, struct s_node **stack_b,
		int *sorted)
{
	int	start;
	int	end;
	int	top;
	int	index;

	start = 0;
	end = 15;
	while (stack_len(*stack_a))
	{
		top = (*stack_a)->data;
		index = get_index(top, sorted);
		if (index >= start && index <= end)
		{
			pb(stack_a, stack_b);
			start++;
			end++;
			if (*stack_a)
			{
				top = (*stack_a)->data;
				index = get_index(top, sorted);
			}
		}
		else if (index > end)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			start++;
			end++;
			if (*stack_a)
			{
				top = (*stack_a)->data;
				index = get_index(top, sorted);
			}
		}
	}
	final_hund_sort(stack_a, stack_b);
}

// void	final_hund_sort(struct s_node **stack_a, struct s_node **stack_b)
// {
// 	int	max;
// 	int	max_index;

// 	while (stack_len(*stack_b))
// 	{
// 		printf("%d\n",stack_len(*stack_b));
// 		max = max_value(*stack_b);
// 		max_index = find_index(*stack_b, max);
// 		if ((*stack_a)->data == max)
// 			pa(stack_b, stack_a);
// 		else if (max_index > (stack_len(*stack_b) / 2))
// 			rrb(stack_b);
// 		else
// 			rb(stack_b);
// 	}
// 	display(*stack_a);
// }
void	final_hund_sort(struct s_node **stack_a, struct s_node **stack_b)
{
    int	max;
    int	max_index;

    while (stack_len(*stack_b))
    {
        printf("%d\n",stack_len(*stack_b));
        max = max_value(*stack_b);
        max_index = find_index(*stack_b, max);
        if ((*stack_a)->data == max)
            pa(stack_b, stack_a);
        else if (max_index > (stack_len(*stack_b) / 2))
            rrb(stack_b);
        else
            rb(stack_b);
    }
    display(*stack_a);
}


