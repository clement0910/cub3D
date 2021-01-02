/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:38:47 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:38:42 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printlspace(char *fmt, int *x, t_struct *flag, va_list arg)
{
	(*x)++;
	if (fmt[*x] == '*')
	{
		flag->nspace = va_arg(arg, int);
		if (flag->nspace < 0)
			flag->nspace = flag->nspace * -1;
		(*x)++;
		return (1);
	}
	while (fmt[*x] >= '0' && fmt[*x] <= '9')
	{
		flag->nspace = (flag->nspace * 10) + (fmt[*x] - '0');
		(*x)++;
	}
	return (1);
}

int		ft_printpreci(char *fmt, int *x, t_struct *flag, va_list arg)
{
	(*x)++;
	if (fmt[*x] == '*')
	{
		flag->precision = va_arg(arg, int);
		(*x)++;
		return (1);
	}
	flag->precision = 0;
	while (fmt[*x] >= '0' && fmt[*x] <= '9')
	{
		flag->precision = (flag->precision * 10) + (fmt[*x] - '0');
		(*x)++;
	}
	return (1);
}

int		ft_printwidth(t_struct *flag, int *x, va_list arg)
{
	flag->widthnbr = va_arg(arg, int);
	(*x)++;
	if (flag->widthnbr < 0)
		flag->nspace = flag->widthnbr * -1;
	else
		flag->space = flag->widthnbr;
	return (1);
}

int		ft_printspace(char *fmt, int *x, t_struct *flag)
{
	while (fmt[*x] >= '0' && fmt[*x] <= '9')
	{
		flag->space = (flag->space * 10) + (fmt[*x] - '0');
		(*x)++;
	}
	return (1);
}

int		ft_printzero(int *x, t_struct *flag)
{
	(*x)++;
	flag->zero = 1;
	return (1);
}
