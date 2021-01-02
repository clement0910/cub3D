/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversiond_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:01:22 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:35:31 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_hd(t_struct *flag, va_list arg)
{
	short int d;

	d = va_arg(arg, int);
	if (flag->precision == 0 && d == 0)
	{
		ft_checknbr(flag);
		return ;
	}
	if (d < 0)
		ft_convertdneg(flag, d);
	else
		ft_convertdpos(flag, d);
}

void	ft_convert_hhd(t_struct *flag, va_list arg)
{
	char d;

	d = va_arg(arg, int);
	if (flag->precision == 0 && d == 0)
	{
		ft_checknbr(flag);
		return ;
	}
	if (d < 0)
		ft_convertdneg(flag, d);
	else
		ft_convertdpos(flag, d);
}

void	ft_convert_ld(t_struct *flag, va_list arg)
{
	long	d;

	d = va_arg(arg, long);
	if (flag->precision == 0 && d == 0)
	{
		ft_checknbr(flag);
		return ;
	}
	if (d < 0)
		ft_convertdneg(flag, d);
	else
		ft_convertdpos(flag, d);
}

void	ft_convert_lld(t_struct *flag, va_list arg)
{
	long long	d;

	d = va_arg(arg, long long);
	if (flag->precision == 0 && d == 0)
	{
		ft_checknbr(flag);
		return ;
	}
	if (d < 0)
		ft_convertdneg(flag, d);
	else
		ft_convertdpos(flag, d);
}

void	ft_convert_d_bonus(t_struct *flag, va_list arg)
{
	long	d;

	d = va_arg(arg, int);
	if (flag->precision == 0 && d == 0)
	{
		ft_checknbr(flag);
		return ;
	}
	if (d < 0)
		ft_convertdneg(flag, d);
	else
		ft_convertdpos(flag, d);
}
