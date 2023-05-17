/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:20:49 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/28 18:43:01 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunnbr(unsigned int i, int *counter)
{
	if (i >= 10)
	{
		ft_putunnbr(i / 10, counter);
		ft_putunnbr(i % 10, counter);
	}
	else
		ft_putchar(i + '0', counter);
}
