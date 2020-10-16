/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:17:54 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:17:57 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	temp;
	int		x;
	int		y;

	y = ft_strlen(str) - 1;
	x = 0;
	while ((unsigned int)x < (ft_strlen(str) / 2))
	{
		temp = str[y];
		str[y] = str[x];
		str[x] = temp;
		y--;
		x++;
	}
	return (str);
}
