/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:01:13 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 15:01:15 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(void)
{
	int	a;
	int	b;
	int	c;

	if (g_top_a == NULL || g_top_a->next == NULL || g_top_a->next->next == NULL)
		return ;
	a = g_top_a->data;
	b = g_top_a->next->data;
	c = g_top_a->next->next->data;

	if (a > b && b < c && c > a)
		sa();
	else if (a > b && b > c)
		sa(), rra();
	else if (a > b && b < c && a > c)
		ra();
	else if (a < b && b > c && c > a)
		sa(), ra();
	else if (a < b && b > c && a > c)
		rra();
 }
 