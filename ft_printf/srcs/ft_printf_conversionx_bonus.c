/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversionx_bonus.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 19:28:25 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 18:29:55 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_x_bonus(t_struct *flag, va_list arg)
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
	str = ft_ulltoa_base(d, "0123456789abcdef");
	ft_convertxutils(flag, str, d);
	free(str);
}

void	ft_convert_lx(t_struct *flag, va_list arg)
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
	str = ft_ulltoa_base(d, "0123456789abcdef");
	ft_convertxutils(flag, str, d);
	free(str);
}

void	ft_convert_llx(t_struct *flag, va_list arg)
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
	str = ft_ulltoa_base(d, "0123456789abcdef");
	ft_convertxutils(flag, str, d);
	free(str);
}

void	ft_convert_hx(t_struct *flag, va_list arg)
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
	str = ft_ulltoa_base(d, "0123456789abcdef");
	ft_convertxutils(flag, str, d);
	free(str);
}

void	ft_convert_hhx(t_struct *flag, va_list arg)
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
	str = ft_ulltoa_base(d, "0123456789abcdef");
	ft_convertxutils(flag, str, d);
	free(str);
}
