/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:15:13 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:15:15 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstptr;
	unsigned char		*srcptr;

	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	if (srcptr < dstptr)
	{
		len++;
		while (--len)
			dstptr[len - 1] = srcptr[len - 1];
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
