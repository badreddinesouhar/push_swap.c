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

void	push(struct s_node **top, int value)
{
	struct s_node	*newnode;

	newnode = (struct s_node *)malloc(sizeof(struct s_node));
	newnode->data = value;
	newnode->next = *top;
	*top = newnode;
}

int	pop(struct s_node **top)
{
	int				value;
	struct s_node	*temp;

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

void	display(struct s_node *top)
{
	while (top != NULL)
	{
		printf("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}
