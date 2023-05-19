/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_avs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:50:36 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 15:51:05 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_valid_input(char **av_split)
{
	int	i;

	i = 0;
	while (av_split[i])
	{
		if (!ft_isdigit_str(av_split[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_same(const char *s1, const char *s2)
{
	int	str1;
	int	str2;

	str1 = ft_atoi(s1);
	str2 = ft_atoi(s2);
	return (str1 - str2);
}

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
