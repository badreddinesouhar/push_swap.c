/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:20 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 09:28:22 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **top)
{
	int	temp;

	if (*top == NULL || (*top)->next == NULL)
	{
		return ;
	}
	temp = (*top)->data;
	(*top)->data = (*top)->next->data;
	(*top)->next->data = temp;
}

void	pa(t_node **src, t_node **dst)
{
	t_node	*temp;

	if (*src == NULL)
	{
		return ;
	}
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	ra(t_node **top)
{
	t_node	*last;

	if (*top == NULL || (*top)->next == NULL)
	{
		return ;
	}
	last = *top;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *top;
	*top = (*top)->next;
	last->next->next = NULL;
}

void	rra(t_node **top)
{
	t_node	*last;
	t_node	*secondlast;

	if (*top == NULL || (*top)->next == NULL)
	{
		return ;
	}
	last = *top;
	secondlast = NULL;
	while (last->next != NULL)
	{
		secondlast = last;
		last = last->next;
	}
	secondlast->next = NULL;
	last->next = *top;
	*top = last;
}
