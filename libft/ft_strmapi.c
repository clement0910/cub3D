/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:17:17 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:17:19 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	x;

	x = 0;
	if (!s)
		return (0);
	if (!(str = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	while (s[x] != '\0')
	{
		str[x] = (*f)(x, s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}
