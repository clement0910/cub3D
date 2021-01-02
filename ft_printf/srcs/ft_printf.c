/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:54:42 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:38:44 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initstruct(t_struct *flag)
{
	flag->precision = -1;
	flag->widthnbr = -1;
	flag->space = 0;
	flag->nspace = 0;
	flag->write = 0;
	flag->snull = 0;
	flag->zero = 0;
	flag->b_hexa = 0;
	flag->b_plus = 0;
	flag->b_space = 0;
	flag->b_h = 0;
	flag->b_l = 0;
}

int		ft_gotoflags(const char *fmt)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int		ft_addflags(t_struct *flag, char *fmt, int *x, va_list arg)
{
	if (fmt[*x] == '-')
		return (ft_printlspace(fmt, x, flag, arg));
	else if (fmt[*x] == '.')
		return (ft_printpreci(fmt, x, flag, arg));
	else if (fmt[*x] == '*')
		return (ft_printwidth(flag, x, arg));
	else if (fmt[*x] > '0' && fmt[*x] <= '9')
		return (ft_printspace(fmt, x, flag));
	else if (fmt[*x] == '0')
		return (ft_printzero(x, flag));
	else if (fmt[*x] == '#')
		return (ft_printb_hexa(x, flag));
	else if (fmt[*x] == '+')
		return (ft_printb_plus(x, flag));
	else if (fmt[*x] == ' ')
		return (ft_printb_space(x, flag));
	else if (fmt[*x] == 'h')
		return (ft_printh_specs(x, flag, fmt));
	else if (fmt[*x] == 'l')
		return (ft_printl_specs(x, flag, fmt));
	return (-1);
}

void	ft_print_parse(const char *fmt, va_list arg, t_struct *flag)
{
	int x;
	int i;
	int temp;

	temp = 0;
	x = ft_gotoflags(fmt);
	i = 0;
	write(1, fmt, x);
	flag->write = flag->write + x;
	if (fmt[x] == '\0')
		return ;
	while (fmt[x])
	{
		if (fmt[x] == '%')
			x++;
		while (temp != -1)
			temp = ft_addflags(flag, (char *)fmt, &x, arg);
		ft_printfunc((char *)fmt, flag, arg, &x);
		temp = 0;
		ft_refreshstruct(flag);
		i = ft_gotoflags(fmt + x);
		write(1, fmt + x, i);
		flag->write = flag->write + i;
		x = x + i;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list		arg;
	t_struct	flag;

	va_start(arg, fmt);
	ft_initstruct(&flag);
	ft_print_parse(fmt, arg, &flag);
	va_end(arg);
	return (flag.write);
}
