/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:11:01 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:20:03 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int x;
	int resultat;
	int neg;

	resultat = 0;
	x = 0;
	neg = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			neg = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		resultat = resultat * 10 + (str[x] - 48);
		x++;
	}
	return (resultat * neg);
}
