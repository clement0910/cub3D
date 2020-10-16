/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:13:22 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:13:24 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_malloc(int n)
{
	long x;
	long y;

	y = n;
	x = 0;
	if (y == 0)
		return (1);
	if (y < 0)
	{
		y = y * -1;
		x++;
	}
	while (y > 0)
	{
		y = y / 10;
		x++;
	}
	return (x);
}

static char		*ft_itoa_convert(char *str, int n)
{
	int		x;
	int		neg;
	long	y;

	y = n;
	x = 0;
	neg = 0;
	if (y < 0)
	{
		neg = 1;
		y = y * -1;
	}
	while (y >= 10)
	{
		str[x++] = (y % 10) + 48;
		y = y / 10;
	}
	if (y >= 0 && y <= 9)
		str[x++] = y + 48;
	if (neg)
		str[x++] = '-';
	str[x] = '\0';
	ft_strrev(str);
	return (str);
}

char			*ft_itoa(int n)
{
	char			*str;

	if (!(str = (char *)malloc((ft_itoa_malloc(n) + 1) * sizeof(char))))
		return (0);
	ft_itoa_convert(str, n);
	return (str);
}
