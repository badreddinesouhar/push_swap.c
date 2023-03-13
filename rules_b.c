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

void	sb(void)
{
	int	temp;

	if (g_top_b == NULL || g_top_b->next == NULL)
	{
		return ;
	}
	temp = g_top_b->data;
	g_top_b->data = g_top_b->next->data;
	g_top_b->next->data = temp;
}

void	pb(void)
{
	struct s_node	*temp;

	if (g_top_a == NULL)
	{
		return ;
	}
	temp = g_top_a;
	g_top_a = g_top_a->next;
	temp->next = g_top_b;
	g_top_b = temp;
}

void	rb(void)
{
	struct s_node	*last;

	if (g_top_b == NULL || g_top_b->next == NULL)
	{
		return ;
	}
	last = g_top_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = g_top_b;
	g_top_b = g_top_b->next;
	last->next->next = NULL;
}

void	rrb(void)
{
	struct s_node	*last;
	struct s_node	*secondlast;

	if (g_top_b == NULL || g_top_b->next == NULL)
	{
		return ;
	}
	last = g_top_b;
	secondlast = NULL;
	while (last->next != NULL)
	{
		secondlast = last;
		last = last->next;
	}
	secondlast->next = NULL;
	last->next = g_top_b;
	g_top_b = last;
}
