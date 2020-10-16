/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:16:07 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:16:08 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_sep(char *str, char c)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == c)
			i++;
		x++;
	}
	if (i == x)
		return (0);
	return (1);
}

static int		ft_split_word(char *str, char c)
{
	int x;
	int i;

	x = 0;
	i = 0;
	if (ft_check_sep(str, c) == 0)
		return (0);
	while (str[x] != '\0')
	{
		if (str[x] != c)
		{
			i++;
			while (str[x] != c)
			{
				x++;
				if (str[x] == '\0')
					return (i);
			}
		}
		x++;
	}
	return (i);
}

static char		*ft_split_malloc(char *s, char c, int *x)
{
	int		j;
	int		u;
	char	*str;

	j = 0;
	u = *x;
	while (s[*x] != c && s[*x] != '\0')
		(*x)++;
	if (!(str = (char *)ft_calloc((*x - u) + 1, sizeof(*str))))
		return (0);
	while (u < *x)
	{
		str[j] = s[u];
		j++;
		u++;
	}
	str[j] = '\0';
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		j;
	char	**str;
	int		x;

	j = 0;
	x = 0;
	if (!(s))
		return (0);
	if (!(str = ft_calloc(ft_split_word((char *)s, c) + 1, sizeof(*str))))
		return (0);
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] == '\0')
			return (str);
		if (!(str[j] = ft_split_malloc((char *)s, c, &x)))
			return (ft_free_tab(str));
		j++;
	}
	return (str);
}
