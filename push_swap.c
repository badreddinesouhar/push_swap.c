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

struct Node	*top_a = NULL;
struct Node	*top_b = NULL;

void	push_a(int value)
{
	struct Node	*newnode;

	newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = value;
	newnode->next = NULL;
	if (top_a == NULL)
	{
		top_a = newnode;
	}
	else
	{
		newnode->next = top_a;
		top_a = newnode;
	}
}

void	push_b(int value)
{
	struct Node	*newnode;

	newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = value;
	newnode->next = NULL;
	if (top_b == NULL)
	{
		top_b = newnode;
	}
	else
	{
		newnode->next = top_b;
		top_b = newnode;
	}
}

int	display_a(void)
{
	struct Node	*temp;

	temp = top_a;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
