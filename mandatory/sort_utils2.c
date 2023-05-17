#include "push_swap.h"

int	get_index(int top, int *arr, int size)
{
	int	i;
	int	last_index;

	last_index = -1;
	i = 0;
	while (i < size)
	{
		if (arr[i] == top)
			last_index = i;
		i++;
	}
	return (last_index);
}

int	max_value(t_node *stack_b)
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

t_node	*find_node(t_node *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->data == value)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

int	find_index(t_node *stack, int value)
{
	t_node *node;
	int index;

	node = find_node(stack, value);
	if (node == NULL)
	{
		return (-1);
	}
	index = 0;
	while (stack != node)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int	is_within_range(int index, int start, int end)
{
	return (index >= start && index <= end);
}

void	move_to_stack_b(t_node **stack_a, t_node **stack_b, int start, int end)
{
	pb(stack_a, stack_b);
	start++;
	end++;
}

void	move_to_stack_b_and_rotate(t_node **stack_a, t_node **stack_b,
		int start, int end)
{
	pb(stack_a, stack_b);
	rb(stack_b);
	start++;
	end++;
}