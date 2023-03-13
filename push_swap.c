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

struct s_node	*g_top_a = NULL;
struct s_node	*g_top_b = NULL;

void	push_a(int value)
{
	struct s_node	*newnode;

	newnode = (struct s_node *)malloc(sizeof(struct s_node));
	newnode->data = value;
	newnode->next = NULL;
	if (g_top_a == NULL)
	{
		g_top_a = newnode;
	}
	else
	{
		newnode->next = g_top_a;
		g_top_a = newnode;
	}
}

void	push_b(int value)
{
	struct s_node	*newnode;

	newnode = (struct s_node *)malloc(sizeof(struct s_node));
	newnode->data = value;
	newnode->next = NULL;
	if (g_top_b == NULL)
	{
		g_top_b = newnode;
	}
	else
	{
		newnode->next = g_top_b;
		g_top_b = newnode;
	}
}

void	display_a(void)
{
	struct s_node	*temp;

	temp = g_top_a;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void	display_b(void)
{
	struct s_node	*temp;

	temp = g_top_b;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
