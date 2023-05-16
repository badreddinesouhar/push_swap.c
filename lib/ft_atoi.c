/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:21:14 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/21 20:21:31 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	sign;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	sign = 1;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] && ft_isdigit(str[i]))
// 	{
// 		res = res * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return (res * sign);
//

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	long res;

	res = 0;
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
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		res = (res * 10) + (str[i++] - '0');
	}
	res = (res * sign);
	if (res < INT_MIN || res > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (res);
}