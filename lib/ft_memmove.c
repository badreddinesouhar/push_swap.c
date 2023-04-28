/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:41:07 by bsouhar           #+#    #+#             */
/*   Updated: 2022/10/21 19:46:21 by bsouhar          ###   ########.fr       */
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