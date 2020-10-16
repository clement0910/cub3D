/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:15:02 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:15:03 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		x;
	unsigned const char	*s1ptr;
	unsigned const char	*s2ptr;

	x = 0;
	s1ptr = s1;
	s2ptr = s2;
	if (n == 0)
		return (0);
	while (s1ptr[x] == s2ptr[x] && x < (n - 1))
		x++;
	return ((unsigned char)s1ptr[x] - (unsigned char)s2ptr[x]);
}
