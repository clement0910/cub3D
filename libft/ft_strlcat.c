/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:16:51 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:16:53 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dest_size;
	size_t	src_size;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (dest_size >= size)
		return (src_size + size);
	while (src[count] && (size - 1 > count + dest_size))
	{
		dst[count + dest_size] = src[count];
		count++;
	}
	dst[count + dest_size] = '\0';
	return (dest_size + src_size);
}
