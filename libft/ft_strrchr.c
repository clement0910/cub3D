/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:17:47 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:17:48 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int x;

	x = ft_strlen(s);
	while (x > 0)
	{
		if (s[x] == c)
			return ((char *)s + x);
		x--;
	}
	if (s[x] == c)
		return ((char *)s);
	return (0);
}
