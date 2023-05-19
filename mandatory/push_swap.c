/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:36:43 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 15:55:11 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **top, int value)
{
	t_node	*newnode;
	t_node	*temp;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = value;
	newnode->next = NULL;
	if (*top == NULL)
		*top = newnode;
	else
	{
		temp = *top;
		while (temp->next)
			temp = temp->next;
		temp->next = newnode;
	}
}
