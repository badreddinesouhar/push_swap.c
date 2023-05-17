/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:16:44 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/28 19:50:13 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putunnbr(unsigned int i, int *counter);
void	ft_puthex(unsigned int i, const char *base, int *counter);
void	ft_print_pointer(unsigned long n, const char *base, int *counter);
int		ft_printf(const char *str, ...);

#endif
