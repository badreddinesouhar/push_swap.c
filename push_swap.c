/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:36:43 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 09:29:03 by bsouhar          ###   ########.fr       */
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

int	pop(t_node **top)
{
	int		value;
	t_node	*temp;

	if (*top == NULL)
	{
		return (-1);
	}
	value = (*top)->data;
	temp = *top;
	*top = (*top)->next;
	free(temp);
	return (value);
}

void	display(t_node *top)
{
	while (top != NULL)
	{
		ft_printf("%d ", top->data);
		top = top->next;
	}
	ft_printf("\n");
}
