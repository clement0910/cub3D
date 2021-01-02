/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversionu_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:45:24 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:35:36 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_u_bonus(t_struct *flag, va_list arg)
{
	unsigned int	d;
	int				len;

	d = va_arg(arg, unsigned int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putunsignednbr_fd(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}

void	ft_convert_lu(t_struct *flag, va_list arg)
{
	unsigned long	d;
	int				len;

	d = va_arg(arg, unsigned long);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putunsignedlongnbr(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}

void	ft_convert_llu(t_struct *flag, va_list arg)
{
	unsigned long long	d;
	int					len;

	d = va_arg(arg, unsigned long long);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putunsignedlongnbr(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}

void	ft_convert_hu(t_struct *flag, va_list arg)
{
	unsigned short int	d;
	int					len;

	d = va_arg(arg, int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putunsignedlongnbr(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}

void	ft_convert_hhu(t_struct *flag, va_list arg)
{
	unsigned char	d;
	int				len;

	d = va_arg(arg, int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putunsignedlongnbr(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}
