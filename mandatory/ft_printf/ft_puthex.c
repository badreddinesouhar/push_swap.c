/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:50:12 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/27 21:29:57 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int i, const char *base, int *counter)
{
	if (i < 16)
		ft_putchar(base[i], counter);
	else
	{
		ft_puthex(i / 16, base, counter);
		ft_putchar(base[i % 16], counter);
	}
}
