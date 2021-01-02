/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversionxmaj_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:47:27 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:35:46 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_xmaj_bonus(t_struct *flag, va_list arg)
{
	unsigned int	d;
	char			*str;

	d = va_arg(arg, unsigned int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	str = ft_ulltoa_base(d, "0123456789ABCDEF");
	ft_convertxmajutils(flag, str, d);
	free(str);
}

void	ft_convert_lxmaj(t_struct *flag, va_list arg)
{
	unsigned long	d;
	char			*str;

	d = va_arg(arg, unsigned long);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	str = ft_ulltoa_base(d, "0123456789ABCDEF");
	ft_convertxmajutils(flag, str, d);
	free(str);
}

void	ft_convert_llxmaj(t_struct *flag, va_list arg)
{
	unsigned long long	d;
	char				*str;

	d = va_arg(arg, unsigned long long);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	str = ft_ulltoa_base(d, "0123456789ABCDEF");
	ft_convertxmajutils(flag, str, d);
	free(str);
}

void	ft_convert_hxmaj(t_struct *flag, va_list arg)
{
	unsigned short int	d;
	char				*str;

	d = va_arg(arg, int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	str = ft_ulltoa_base(d, "0123456789ABCDEF");
	ft_convertxmajutils(flag, str, d);
	free(str);
}

void	ft_convert_hhxmaj(t_struct *flag, va_list arg)
{
	unsigned char	d;
	char			*str;

	d = va_arg(arg, int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	str = ft_ulltoa_base(d, "0123456789ABCDEF");
	ft_convertxmajutils(flag, str, d);
	free(str);
}
