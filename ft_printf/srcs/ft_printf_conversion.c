/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 10:15:14 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 18:29:55 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(t_struct *flag, va_list arg)
{
	char	*str;
	int		len;

	str = va_arg(arg, char *);
	if (str == NULL)
		len = ft_convert_snull(&str, flag);
	else
		len = (int)ft_strlen(str);
	ft_convert_sutils(flag, len);
	if (flag->precision >= 0)
	{
		if (flag->precision == 0)
			len = 0;
		else
			len = (flag->precision > len) ? len : flag->precision;
	}
	ft_multipleswrite(flag->space, ' ', flag);
	write(1, str, len);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
	if (flag->snull == 1)
		free(str);
}

void	ft_convert_d(t_struct *flag, va_list arg)
{
	if (flag->b_h == 1)
		ft_convert_hd(flag, arg);
	else if (flag->b_h == 2)
		ft_convert_hhd(flag, arg);
	else if (flag->b_l == 1)
		ft_convert_ld(flag, arg);
	else if (flag->b_l == 2)
		ft_convert_lld(flag, arg);
	else
		ft_convert_d_bonus(flag, arg);
}

void	ft_convert_c(t_struct *flag, va_list arg)
{
	unsigned int c;

	c = (unsigned char)va_arg(arg, int);
	ft_multipleswrite(flag->space - 1, ' ', flag);
	write(1, &c, 1);
	flag->write++;
	ft_multipleswrite(flag->nspace - 1, ' ', flag);
}

void	ft_convert_p(t_struct *flag, va_list arg)
{
	unsigned long long int	ptr;
	char					*str;
	int						len;

	ptr = (unsigned long long int)va_arg(arg, void *);
	str = ft_ulltoa_base(ptr, "0123456789abcdef");
	len = ft_strlen(str);
	if (ptr == 0 && flag->precision == 0)
		len = 0;
	ft_multipleswrite(flag->space - (len + 2), ' ', flag);
	write(1, "0x", 2);
	write(1, str, len);
	flag->write = flag->write + (len + 2);
	ft_multipleswrite(flag->nspace - (len + 2), ' ', flag);
	free(str);
}

void	ft_convert_u(t_struct *flag, va_list arg)
{
	if (flag->b_h == 1)
		ft_convert_hu(flag, arg);
	else if (flag->b_h == 2)
		ft_convert_hhu(flag, arg);
	else if (flag->b_l == 1)
		ft_convert_lu(flag, arg);
	else if (flag->b_l == 2)
		ft_convert_llu(flag, arg);
	else
		ft_convert_u_bonus(flag, arg);
}
