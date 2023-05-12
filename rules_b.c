/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:48:57 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 10:49:00 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(struct s_node **top_b)
{
	int	temp;

	if (*top_b == NULL || (*top_b)->next == NULL)
	{
		return ;
	}
	temp = (*top_b)->data;
	(*top_b)->data = (*top_b)->next->data;
	(*top_b)->next->data = temp;
}

void	pb(struct s_node **top_a, struct s_node **top_b)
{
	struct s_node	*temp;

	if (*top_a == NULL)
		return ;
	temp = *top_a;
	*top_a = (*top_a)->next;
	temp->next = NULL;
	if (*top_b == NULL)
		*top_b = temp;
	else
	{
		temp->next = *top_b;
		*top_b = temp;
	}
}

void	rb(struct s_node **top_b)
{
	struct s_node	*last;

	if (*top_b == NULL || (*top_b)->next == NULL)
	{
		return ;
	}
	last = *top_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *top_b;
	*top_b = (*top_b)->next;
	last->next->next = NULL;
}

void	rrb(struct s_node **top_b)
{
	struct s_node	*last;
	struct s_node	*secondlast;

	if (*top_b == NULL || (*top_b)->next == NULL)
	{
		return ;
	}
	last = *top_b;
	secondlast = NULL;
	while (last->next != NULL)
	{
		secondlast = last;
		last = last->next;
	}
	secondlast->next = NULL;
	last->next = *top_b;
	*top_b = last;
}
