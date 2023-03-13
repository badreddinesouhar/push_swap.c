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

	if (g_top_a == NULL || g_top_a->next == NULL)
	{
		return ;
	}
	temp = g_top_a->data;
	g_top_a->data = g_top_a->next->data;
	g_top_a->next->data = temp;
}

void	ss(void)
{
	sa();
	sb();
}

void	pa(void)
{
	struct s_node	*temp;

	if (g_top_b == NULL)
	{
		return ;
	}
	temp = g_top_b;
	g_top_b = g_top_b->next;
	temp->next = g_top_a;
	g_top_a = temp;
}

void	ra(void)
{
	struct s_node	*last;

	if (g_top_a == NULL || g_top_a->next == NULL)
	{
		return ;
	}
	last = g_top_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = g_top_a;
	g_top_a = g_top_a->next;
	last->next->next = NULL;
}

void	rr(void)
{
	ra();
	rb();
}

void	rra(void)
{
	struct s_node	*second_last;
	struct s_node	*last;

	if (g_top_a == NULL || g_top_a->next == NULL)
	{
		return ;
	}
	second_last = g_top_a;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	last = second_last->next;
	second_last->next = NULL;
	last->next = g_top_a;
	g_top_a = last;
}

void	rrr(void)
{
	rra();
	rrb();
}
