/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:17:39 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:17:41 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t x;
	size_t i;

	x = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[x] != '\0' && x < len)
	{
		if (s1[x] == s2[0])
		{
			i = 0;
			while (s1[x + i] == s2[i] && (x + i) < len
				&& s1[x + i] != '\0' && s2[i] != '\0')
			{
				i++;
				if (s2[i] == '\0')
					return ((char *)s1 + x);
			}
		}
		x++;
	}
	return (0);
}
