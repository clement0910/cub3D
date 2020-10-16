/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:16:35 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:16:36 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == c)
			return ((char *)str + x);
		x++;
	}
	if (c == '\0')
		return ((char *)str + x);
	return (0);
}
