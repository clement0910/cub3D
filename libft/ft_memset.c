/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:15:21 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:15:23 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	x;
	unsigned char	*ptr;

	ptr = b;
	x = 0;
	while (x < len)
	{
		ptr[x] = (unsigned char)c;
		x++;
	}
	return ((void *)b);
}
