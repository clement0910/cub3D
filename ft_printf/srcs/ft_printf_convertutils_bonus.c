/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertutils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:01:55 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:35:50 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_checknbr(t_struct *flag)
{
	flag->space = flag->space - flag->b_plus;
	flag->space = flag->space - flag->b_space;
	ft_multipleswrite(flag->space, ' ', flag);
	ft_multipleswrite(flag->b_plus, '+', flag);
	ft_multipleswrite(flag->b_space, ' ', flag);
	flag->nspace = flag->nspace - flag->b_plus;
	flag->nspace = flag->nspace - flag->b_space;
	ft_multipleswrite(flag->nspace, ' ', flag);
}

void	ft_convertxutils(t_struct *flag, char *str, unsigned long long d)
{
	int len;

	len = ft_strlen(str);
	ft_convert_dutils(flag, len);
	if (flag->b_hexa == 1 && d != 0)
	{
		flag->nspace = flag->nspace - 2;
		flag->space = flag->space - 2;
	}
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->b_hexa == 1 && d != 0)
	{
		write(1, "0x", 2);
		flag->write = flag->write + 2;
	}
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	write(1, str, len);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}

void	ft_convertxmajutils(t_struct *flag, char *str, unsigned long long d)
{
	int len;

	len = ft_strlen(str);
	ft_convert_dutils(flag, len);
	if (flag->b_hexa == 1 && d != 0)
	{
		flag->nspace = flag->nspace - 2;
		flag->space = flag->space - 2;
	}
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->b_hexa == 1 && d != 0)
	{
		write(1, "0X", 2);
		flag->write = flag->write + 2;
	}
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	write(1, str, len);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}
