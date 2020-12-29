/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_flags_bonus.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 21:27:03 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 18:29:55 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printb_hexa(int *x, t_struct *flag)
{
	(*x)++;
	flag->b_hexa = 1;
	return (1);
}

int		ft_printb_plus(int *x, t_struct *flag)
{
	(*x)++;
	flag->b_plus = 1;
	return (1);
}

int		ft_printb_space(int *x, t_struct *flag)
{
	(*x)++;
	flag->b_space = 1;
	return (1);
}

int		ft_printh_specs(int *x, t_struct *flag, char *fmt)
{
	(*x)++;
	if (fmt[*x] == 'h')
	{
		flag->b_h = 2;
		(*x)++;
	}
	else
		flag->b_h = 1;
	return (1);
}

int		ft_printl_specs(int *x, t_struct *flag, char *fmt)
{
	(*x)++;
	if (fmt[*x] == 'l')
	{
		flag->b_l = 2;
		(*x)++;
	}
	else
		flag->b_l = 1;
	return (1);
}
