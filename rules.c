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

	if (top_a == NULL || top_a->next == NULL)
	{
		return ; // Do nothing if there is only one or no elements.
	}
	temp = top_a->data;
	top_a->data = top_a->next->data;
	top_a->next->data = temp;
}
