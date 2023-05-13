/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:45:03 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/28 18:25:41 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
	{
		ft_putstr("-2", counter);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-n, counter);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0', counter);
	}
	else
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
}
