/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertutils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:15:42 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:38:35 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_convert_snull(char **str, t_struct *flag)
{
	flag->snull = 1;
	*str = ft_strdup("(null)");
	return (6);
}

void	ft_convert_sutils(t_struct *flag, int len)
{
	if (flag->space > 0)
	{
		if (flag->precision > 0 && flag->precision < len)
			flag->space = flag->space - flag->precision;
		else if (flag->precision == 0)
			flag->space = flag->space;
		else
			flag->space = flag->space - len;
	}
	if (flag->nspace > 0)
	{
		if (flag->precision > 0 && flag->precision < len)
			flag->nspace = flag->nspace - flag->precision;
		else if (flag->precision == 0)
			flag->space = flag->space;
		else
			flag->nspace = flag->nspace - len;
	}
}

void	ft_convert_dutils(t_struct *flag, int len)
{
	if (flag->precision >= 0)
		flag->zero = 0;
	if (flag->space > 0)
	{
		flag->precision = (flag->precision > len) ? flag->precision : len;
		flag->space = flag->space - flag->precision;
		flag->space = flag->space - flag->b_plus;
		flag->space = flag->space - flag->b_space;
	}
	if (flag->nspace > 0)
	{
		flag->precision = (flag->precision > len) ? flag->precision : len;
		flag->nspace = flag->nspace - flag->precision;
		flag->nspace = flag->nspace - flag->b_plus;
		flag->nspace = flag->nspace - flag->b_space;
	}
	if (flag->precision > 0)
		flag->precision = flag->precision - len;
}

void	ft_convertdneg(t_struct *flag, long long d)
{
	int len;

	d = -d;
	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	flag->space--;
	flag->nspace--;
	if ((flag->b_plus == 1 || flag->b_space == 1) && flag->space > 0)
		flag->space++;
	if ((flag->b_plus == 1 || flag->b_space == 1) && flag->nspace > 0)
		flag->nspace++;
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
	{
		ft_multipleswrite(1, '-', flag);
		ft_multipleswrite(flag->space, '0', flag);
	}
	else
		ft_multipleswrite(1, '-', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putlongnbr(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}

void	ft_convertdpos(t_struct *flag, unsigned long long d)
{
	int len;

	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	ft_multipleswrite(flag->b_space, ' ', flag);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
	{
		if (flag->b_plus == 1)
			ft_multipleswrite(1, '+', flag);
		ft_multipleswrite(flag->space, '0', flag);
	}
	else
	{
		if (flag->b_plus == 1)
			ft_multipleswrite(1, '+', flag);
	}
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putunsignedlongnbr(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}
