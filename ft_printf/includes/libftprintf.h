/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:35:45 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 14:41:11 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../../libft/libft.h"
# include <inttypes.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int				ft_printf(const char *format, ...)
				 __attribute__((format(printf,1,2)));

typedef	struct	s_struct
{
	int		widthnbr;
	int		precision;
	int		nspace;
	int		space;
	int		write;
	uint8_t	snull:1;
	uint8_t	zero:1;

	uint8_t b_hexa:1;
	uint8_t b_plus:1;
	uint8_t b_space:1;

	uint8_t b_h:2;
	uint8_t b_l:2;
}				t_struct;

int				ft_printlspace(char *fmt, int *x, t_struct *flag, va_list arg);
int				ft_printpreci(char *fmt, int *x, t_struct *flag, va_list arg);
int				ft_printwidth(t_struct *flag, int *x, va_list arg);
int				ft_printspace(char *fmt, int *x, t_struct *flag);
int				ft_printzero(int *x, t_struct *flag);
void			ft_convert_s(t_struct *flag, va_list arg);
void			ft_convert_d(t_struct *flag, va_list arg);
void			ft_convert_c(t_struct *flag, va_list arg);
void			ft_convert_p(t_struct *flag, va_list arg);
void			ft_convert_u(t_struct *flag, va_list arg);
void			ft_convert_x(t_struct *flag, va_list arg);
void			ft_convert_xmaj(t_struct *flag, va_list arg);
void			ft_convert_percent(t_struct *flag);
int				findindex(char element);
void			ft_printfunc(char *fmt, t_struct *flag, va_list arg, int *x);
void			ft_multipleswrite(int x, char c, t_struct *flag);
int				ft_ullintlen(unsigned long long int nbr, char *base);
char			*ft_ulltoa_base(unsigned long long int nbr, char *base);
int				ft_gotoflags(const char *fmt);
int				ft_addflags(t_struct *flag, char *fmt, int *x, va_list arg);
void			ft_print_parse(const char *fmt, va_list arg, t_struct *flag);
int				ft_convert_snull(char **str, t_struct *flag);
void			ft_convert_sutils(t_struct *flag, int len);
void			ft_convert_dutils(t_struct *flag, int len);
void			ft_convertdneg(t_struct *flag, long long d);
void			ft_initstruct(t_struct *flag);
void			ft_refreshstruct(t_struct *flag);

int				ft_printb_hexa(int *x, t_struct *flag);
int				ft_printb_plus(int *x, t_struct *flag);
int				ft_printb_space(int *x, t_struct *flag);
int				ft_printh_specs(int *x, t_struct *flag, char *fmt);
int				ft_printl_specs(int *x, t_struct *flag, char *fmt);

void			ft_convert_d_bonus(t_struct *flag, va_list arg);
void			ft_convert_hd(t_struct *flag, va_list arg);
void			ft_convert_hhd(t_struct *flag, va_list arg);
void			ft_convert_ld(t_struct *flag, va_list arg);
void			ft_convert_lld(t_struct *flag, va_list arg);

void			ft_convert_x_bonus(t_struct *flag, va_list arg);
void			ft_convert_hx(t_struct *flag, va_list arg);
void			ft_convert_hhx(t_struct *flag, va_list arg);
void			ft_convert_lx(t_struct *flag, va_list arg);
void			ft_convert_llx(t_struct *flag, va_list arg);

void			ft_convert_xmaj_bonus(t_struct *flag, va_list arg);
void			ft_convert_hxmaj(t_struct *flag, va_list arg);
void			ft_convert_hhxmaj(t_struct *flag, va_list arg);
void			ft_convert_lxmaj(t_struct *flag, va_list arg);
void			ft_convert_llxmaj(t_struct *flag, va_list arg);

void			ft_convert_u_bonus(t_struct *flag, va_list arg);
void			ft_convert_lu(t_struct *flag, va_list arg);
void			ft_convert_llu(t_struct *flag, va_list arg);
void			ft_convert_hu(t_struct *flag, va_list arg);
void			ft_convert_hhu(t_struct *flag, va_list arg);

void			ft_checknbr(t_struct *flag);
void			ft_convertdpos(t_struct *flag, unsigned long long d);
void			ft_convertxutils(t_struct *flag, char *str, unsigned long
				long d);
void			ft_convertxmajutils(t_struct *flag, char *str, unsigned long
				long d);
void			ft_convert_n(t_struct *flag, va_list arg);

void			ft_putlongnbr(long long x, int fd);
void			ft_putunsignedlongnbr(unsigned long long x,
				int fd);
#endif
