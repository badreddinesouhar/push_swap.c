/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:21:14 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 17:55:34 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	error_check(const char *str, int i, int sign, long nb)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		nb = (nb * 10) + (str[i] - '0');
		if (nb < INT_MIN || nb > INT_MAX)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	nb = (nb * sign);
	return (nb);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (error_check(str, i, sign, nb));
}
