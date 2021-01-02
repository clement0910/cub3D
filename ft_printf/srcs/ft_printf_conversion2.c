/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:22:16 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:35:28 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_x(t_struct *flag, va_list arg)
{
	if (flag->b_h == 1)
		ft_convert_hx(flag, arg);
	else if (flag->b_h == 2)
		ft_convert_hhx(flag, arg);
	else if (flag->b_l == 1)
		ft_convert_lx(flag, arg);
	else if (flag->b_l == 2)
		ft_convert_llx(flag, arg);
	else
		ft_convert_x_bonus(flag, arg);
}

void	ft_convert_xmaj(t_struct *flag, va_list arg)
{
	if (flag->b_h == 1)
		ft_convert_hxmaj(flag, arg);
	else if (flag->b_h == 2)
		ft_convert_hhxmaj(flag, arg);
	else if (flag->b_l == 1)
		ft_convert_lxmaj(flag, arg);
	else if (flag->b_l == 2)
		ft_convert_llxmaj(flag, arg);
	else
		ft_convert_xmaj_bonus(flag, arg);
}

void	ft_convert_percent(t_struct *flag)
{
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space - 1, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space - 1, '0', flag);
	write(1, "%", 1);
	flag->write++;
	ft_multipleswrite(flag->nspace - 1, ' ', flag);
}

int		findindex(char element)
{
	int		x;
	char	tab[10];

	x = 0;
	tab[0] = 's';
	tab[1] = 'd';
	tab[2] = 'c';
	tab[3] = 'p';
	tab[4] = 'u';
	tab[5] = 'x';
	tab[6] = 'X';
	tab[7] = 'i';
	tab[8] = 'n';
	tab[9] = 0;
	while (tab[x])
	{
		if (tab[x] == element)
			return (x);
		if (element == '%')
			return (-2);
		x++;
	}
	return (-1);
}

void	ft_printfunc(char *fmt, t_struct *flag, va_list arg, int *x)
{
	void	(*tabfunction[9])(t_struct *, va_list);
	int		index;

	tabfunction[0] = ft_convert_s;
	tabfunction[1] = ft_convert_d;
	tabfunction[2] = ft_convert_c;
	tabfunction[3] = ft_convert_p;
	tabfunction[4] = ft_convert_u;
	tabfunction[5] = ft_convert_x;
	tabfunction[6] = ft_convert_xmaj;
	tabfunction[7] = ft_convert_d;
	tabfunction[8] = ft_convert_n;
	index = findindex(fmt[*x]);
	if (index == -1)
		return ;
	if (index == -2)
	{
		ft_convert_percent(flag);
		(*x)++;
		return ;
	}
	(*tabfunction[index])(flag, arg);
	(*x)++;
}
