/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:42:17 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 14:49:10 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignednbr_fd(unsigned int x, int fd)
{
	if (x < 10)
		ft_putchar_fd(x + 48, fd);
	else
	{
		ft_putunsignednbr_fd(x / 10, fd);
		ft_putunsignednbr_fd(x % 10, fd);
	}
}
