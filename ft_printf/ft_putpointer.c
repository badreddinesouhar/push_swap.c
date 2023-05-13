/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:52 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/28 19:57:04 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(unsigned long n, const char *base, int *counter)
{
	if (n >= 16)
		ft_print_pointer(n / 16, base, counter);
	ft_putchar(base[n % 16], counter);
}
