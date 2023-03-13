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

void	sa(void)
{
	int	temp;

	if (top_a == NULL || top_a->next == NULL)
	{
		return ;
	}
	temp = top_a->data;
	top_a->data = top_a->next->data;
	top_a->next->data = temp;
}

void	sb(void)
{
	int	temp;

	if (top_b == NULL || top_b->next == NULL)
	{
		return ;
	}
	temp = top_b->data;
	top_b->data = top_b->next->data;
	top_b->next->data = temp;
}

void	ss(void)
{
	sa();
	sb();
}

void	pa(void)
{
	struct Node	*temp;

	if (top_b == NULL)
	{
		return ;
	}
	temp = top_b;
	top_b = top_b->next;
	temp->next = top_a;
	top_a = temp;
}

void	pb(void)
{
	struct Node	*temp;

	if (top_a == NULL)
	{
		return ;
	}
	temp = top_a;
	top_a = top_a->next;
	temp->next = top_b;
	top_b = temp;
}

void	ra(void)
{
	struct Node	*last;

	if (top_a == NULL || top_a->next == NULL)
	{
		return ;
	}
	last = top_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = top_a;
	top_a = top_a->next;
	last->next->next = NULL;
}

void	rb(void)
{
	struct Node	*last;

	if (top_b == NULL || top_b->next == NULL)
	{
		return ;
	}
	last = top_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = top_b;
	top_b = top_b->next;
	last->next->next = NULL;
}

void	rr(void)
{
	ra();
	rb();
}

void	rra(void)
{
	struct Node	*second_last;
	struct Node	*last;

	if (top_a == NULL || top_a->next == NULL)
	{
		return ;
	}
	second_last = top_a;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	last = second_last->next;
	second_last->next = NULL;
	last->next = top_a;
	top_a = last;
}

void	rrb(void)
{
	struct Node	*last;
	struct Node	*secondLast;

	if (top_b == NULL || top_b->next == NULL)
	{
		return ;
	}
	last = top_b;
	secondLast = NULL;
	while (last->next != NULL)
	{
		secondLast = last;
		last = last->next;
	}
	secondLast->next = NULL;
	last->next = top_b;
	top_b = last;
}

void	rrr(void)
{
	rra();
	rrb();
}
