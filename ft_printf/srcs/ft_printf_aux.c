/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:11:02 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:35:15 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_multipleswrite(int x, char c, t_struct *flag)
{
	while (x > 0)
	{
		write(1, &c, 1);
		flag->write++;
		x--;
	}
}

int			ft_ullintlen(unsigned long long nbr, char *base)
{
	int lenbase;
	int x;

	x = 0;
	if (nbr == 0)
		return (1);
	lenbase = ft_strlen(base);
	while (nbr > 0)
	{
		nbr = nbr / lenbase;
		x++;
	}
	return (x);
}

char		*ft_ulltoa_base(unsigned long long int nbr, char *base)
{
	int		x;
	int		m;
	char	*str;
	int		lenbase;

	x = 0;
	if (nbr == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	lenbase = ft_strlen(base);
	m = ft_ullintlen(nbr, base);
	str = malloc((m + 1) * sizeof(char));
	while (nbr > 0)
	{
		str[x] = base[nbr % lenbase];
		nbr = nbr / lenbase;
		x++;
	}
	str[x] = '\0';
	ft_strrev(str);
	return (str);
}

void		ft_refreshstruct(t_struct *flag)
{
	flag->precision = -1;
	flag->widthnbr = -1;
	flag->space = 0;
	flag->nspace = 0;
	flag->snull = 0;
	flag->zero = 0;
	flag->b_hexa = 0;
	flag->b_plus = 0;
	flag->b_space = 0;
	flag->b_l = 0;
	flag->b_h = 0;
}
