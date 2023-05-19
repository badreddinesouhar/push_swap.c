/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:41:07 by bsouhar           #+#    #+#             */
/*   Updated: 2023/05/19 17:48:15 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*nsrc;
	unsigned char	*ndst;

	nsrc = (unsigned char *)src;
	ndst = (unsigned char *)dst;
	if (dst > src)
		while (len--)
			ndst[len] = nsrc[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
