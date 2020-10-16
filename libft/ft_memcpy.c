/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:15:07 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:15:09 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		x;
	unsigned char		*dstptr;
	unsigned const char	*srcptr;

	srcptr = src;
	dstptr = dst;
	x = 0;
	if (!src && !dst)
		return (0);
	while (x < n)
	{
		dstptr[x] = srcptr[x];
		x++;
	}
	return (dst);
}
