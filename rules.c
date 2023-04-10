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

void	sa(struct s_node **top)
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

void	pa(struct s_node **src, struct s_node **dst)
{
	struct s_node	*temp;

	if (*src == NULL)
	{
		return ;
	}
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	ra(struct s_node **top)
{
	struct s_node	*last;

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

void	rra(struct s_node **top)
{
	struct s_node	*last;
	struct s_node	*secondlast;

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
