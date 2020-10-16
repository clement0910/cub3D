/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:15:37 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:15:39 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int x;

	x = 0;
	if (s == NULL)
		return ;
	while (s[x] != '\0')
		ft_putchar_fd(s[x++], fd);
	ft_putchar_fd('\n', fd);
}
