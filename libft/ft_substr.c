/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:18:15 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:18:17 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	x;
	unsigned int	i;
	int				m;
	char			*str;

	i = 0;
	x = start;
	m = len;
	if (!(s))
		return (0);
	if (ft_strlen(s + start) < len)
		m = ft_strlen(s + start);
	if (start > (unsigned int)ft_strlen(s))
		return (str = ft_calloc(1, sizeof(char)));
	if (!(str = (char *)malloc((m + 1) * sizeof(char))))
		return (0);
	while (i < (unsigned int)m)
	{
		str[i] = s[x];
		x++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
