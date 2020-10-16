/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:14:55 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:14:56 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int				x;
	unsigned char				*sptr;

	x = 0;
	sptr = (unsigned char *)s;
	while (x < n)
	{
		if (sptr[x] == (unsigned char)c)
			return ((char *)s + x);
		x++;
	}
	return (0);
}
