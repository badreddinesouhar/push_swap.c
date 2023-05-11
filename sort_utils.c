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

// int	stack_len(struct s_node *stack)
// {
// 	int				length;
// 	struct s_node	*current;

// 	length = 0;
// 	current = stack;
// 	while (current != NULL)
// 	{
// 		length++;
// 		current = current->next;
// 	}
// 	return (length);
// }
// int	min_val(struct s_node **stack)
// {
// 	int	*min;
// 	struct s_node	*tmp;

// 	if (!stack)
// 		return (NULL);
// 	min = &(stack->data);
// 	tmp = stack->next;
// 	while (tmp)
// 	{
// 		if (tmp->data < *min)
// 			min = &(tmp->data);
// 		tmp = tmp->next;
// 	}
// 	return (min);
// }

// int	min_idx(struct s_node **stack)
// {
// 	int			*min_index;
// 	unsigned int	index;
// 	struct s_node	*tmp;

// 	if (!stack)
// 		return (NULL);
// 	min_index = &index;
// 	index = 0;
// 	tmp = stack->next;
// 	while (tmp)
// 	{
// 		if (tmp->data < stack->data)
// 			++index;
// 		tmp = tmp->next;
// 	}
// 	return (min_index);
// }


// void sort(struct s_node *stack_a, struct s_node *stack_b, int *sorted_arr)
// {
//     int len;
 
//     (void)sorted_arr;
//     len = stack_len(stack_a);
//   	if (len == 2)
// 		sa(&stack_a);
// 	else if (len == 3)
// 		sort_three_numbers(&stack_a);
// 	else if (len <= 5)
// 		sort_five_numbers(&stack_a, &stack_b);
// 	// else if (len <= 100)
// 	// 	sort_hund_numbers(&stack_a, &stack_b, sorted_arr, 0, 15);
// 	// else
// 	// 	sort_fihund_numbers(&stack_a, &stack_b, sorted_arr, 0, 30);
// }

int stack_len(struct s_node *stack)
{
    int length = 0;
    struct s_node *current = stack;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

int min_val(struct s_node **stack)
{
    int *min;
    struct s_node *tmp;

    if (*stack == NULL)
        return -1;
    min = &(*stack)->data;
    tmp = (*stack)->next;
    while (tmp != NULL)
    {
        if (tmp->data < *min)
            min = &tmp->data;
        tmp = tmp->next;
    }
    return *min;
}

int min_idx(struct s_node **stack)
{
    size_t min_index = 0;
    struct s_node *tmp;

    if (*stack == NULL)
        return -1;
    tmp = (*stack)->next;
    while (tmp != NULL)
    {
        if (tmp->data < (*stack)->data)
            min_index++;
        tmp = tmp->next;
    }
    return (int)min_index;
}

void sort(struct s_node *stack_a, struct s_node *stack_b, int *sorted_arr)
{
    int len;
    (void)sorted_arr;
    len = stack_len(stack_a);
    if (len == 2)
        sa(&stack_a);
    else if (len == 3)
        sort_three_numbers(&stack_a);
    else if (len <= 5)
        sort_five_numbers(&stack_a, &stack_b);
    // else if (len <= 100)
    //     sort_hund_numbers(&stack_a, &stack_b, sorted_arr, 0, 15);
    // else
    //     sort_fihund_numbers(&stack_a, &stack_b, sorted_arr, 0, 30);
}
