/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:18:05 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:18:06 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		x;
	int		i;
	int		t;

	t = 0;
	x = 0;
	if (!s1 || !set)
		return (0);
	i = (ft_strlen(s1) == 0) ? 1 : ft_strlen(s1);
	while (ft_chrcmp((char *)set, s1[x]) == 0)
		x++;
	while ((ft_chrcmp((char *)set, s1[i - 1]) == 0))
	{
		i--;
		if (i == 0)
			return (str = ft_calloc(1, sizeof(char)));
	}
	if (!(str = malloc(((i - x) + 1) * sizeof(char))))
		return (0);
	while (x < i)
		str[t++] = s1[x++];
	str[t] = '\0';
	return (str);
}
