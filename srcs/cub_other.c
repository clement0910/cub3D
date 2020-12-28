/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:59:51 by csapt             #+#    #+#             */
/*   Updated: 2020/12/28 10:20:02 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_free_static_tab(char **tab, int size)
{
	int x;

	x = 0;
	if (!tab)
		return ;
	if (size == 0)
		return ;
	while (x < size)
	{
		if (tab)
			free(tab[x]);
		x++;
	}
}

int		ft_atoi_parse(char *str, int *x)
{
	size_t resultat;

	resultat = 0;
	while ((str[*x] >= 9 && str[*x] <= 13) || str[*x] == ' ')
		(*x)++;
	if (ft_isdigit(str[*x]) == 0)
		return (-1);
	while (str[*x] >= '0' && str[*x] <= '9')
	{
		resultat = resultat * 10 + (str[*x] - 48);
		(*x)++;
	}
	while ((str[*x] >= 9 && str[*x] <= 13) || str[*x] == ' ')
		(*x)++;
	if (resultat > 2147483647)
		return (2147483646);
	return ((int)resultat);
}
