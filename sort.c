/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:01:13 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/10 10:22:35 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(struct s_node **top)
{
	int	a;
	int	b;
	int	c;

	if (*top == NULL || (*top)->next == NULL || (*top)->next->next == NULL)
	{
		return ;
	}
	a = (*top)->data;
	b = (*top)->next->data;
	c = (*top)->next->next->data;
	if (a > b && b < c && c > a)
	{
		sa(top);
	}
	else if (a > b && b > c)
	{
		sa(top);
		rra(top);
	}
	else if (a > b && b < c && a > c)
	{
		ra(top);
	}
	else if (a < b && b > c && c > a)
	{
		sa(top);
		ra(top);
	}
	else if (a < b && b > c && a > c)
	{
		rra(top);
	}
}

//void sort_five_numbers(struct s_node **top)
