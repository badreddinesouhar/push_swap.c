/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:19:33 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/28 20:36:07 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_all(const char c, va_list argmnts, int *counter)
{
	if (c == '%')
		ft_putchar('%', counter);
	else if (c == 'c')
		ft_putchar(va_arg(argmnts, int), counter);
	else if (c == 's')
		ft_putstr(va_arg(argmnts, char *), counter);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(argmnts, long int), counter);
	else if (c == 'x')
		ft_puthex(va_arg(argmnts, unsigned int), "0123456789abcdef", counter);
	else if (c == 'X')
		ft_puthex(va_arg(argmnts, unsigned int), "0123456789ABCDEF", counter);
	else if (c == '%')
		ft_putchar('%', counter);
	else if (c == 'u')
		ft_putunnbr(va_arg(argmnts, unsigned int), counter);
	else if (c == 'p')
	{
		ft_putstr("0x", counter);
		ft_print_pointer(va_arg(argmnts, unsigned long), "0123456789abcdef",
			counter);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	arg;

	i = 0;
	counter = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &counter);
		else
		{
			i++;
			ft_print_all(str[i], arg, &counter);
		}
		i++;
	}
	va_end(arg);
	return (counter);
}
