/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:34:03 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/21 20:34:20 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = (long int)n;
	i = ft_nbrlen(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (nb == 0)
		str[0] = nb + 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	return (str);
}
