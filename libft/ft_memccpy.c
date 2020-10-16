/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:14:49 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:14:50 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		x;
	unsigned char		*dstptr;
	unsigned const char	*srcptr;

	srcptr = (unsigned const char *)src;
	dstptr = (unsigned char *)dst;
	x = 0;
	while (x < n)
	{
		dstptr[x] = srcptr[x];
		if (srcptr[x] == (unsigned char)c)
		{
			x++;
			return (dst + x);
		}
		x++;
	}
	return (0);
}
