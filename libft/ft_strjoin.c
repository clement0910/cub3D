/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:16:45 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:16:46 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		i;
	char	*str;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = (char *)malloc(ft_strlen((char *)s1) +
	ft_strlen((char *)s2) + 1)))
		return (0);
	while (s1[x] != '\0')
		str[x++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[x++] = s2[i++];
	str[x] = '\0';
	return (str);
}
