/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:59:51 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 17:56:27 by csapt            ###   ########lyon.fr   */
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

void	ft_strcpy_cub(char *src, char *dst)
{
	size_t	x;

	x = 0;
	if (!src || !dst)
		return ;
	while (src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
}

int		freestr_return(char *str, int exit)
{
	free(str);
	return (exit);
}

int		ft_strcmp(char *s1, char *s2)
{
	int x;

	x = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}
