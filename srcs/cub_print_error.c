/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:05:08 by csapt             #+#    #+#             */
/*   Updated: 2020/12/27 22:08:34 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_error(char *error, bool warn)
{
	if (warn)
	{
		ft_putstr_fd(ORANGE_ERROR, 1);
		ft_putendl_fd("WARNING !", 1);
		ft_putendl_fd(error, 1);
		ft_putstr_fd(RESET_ERROR, 1);
	}
	else
	{
		ft_putstr_fd(RED_ERROR, 1);
		ft_putstr_fd(error, 1);
		ft_putendl_fd(" Error !", 1);
		ft_putstr_fd(RESET_ERROR, 1);
	}
}

void	*return_message(char *error, char *details)
{
	if (error)
	{
		ft_putstr_fd(error, 1);
		if (details)
			ft_putendl_fd(details, 1);
		else
			write(1, "\n", 1);
	}
	return (NULL);
}

int		return_message_i(char *error, char *details, int err)
{
	if (error)
	{
		ft_putstr_fd(error, 1);
		if (details)
			ft_putendl_fd(details, 1);
		else
			write(1, "\n", 1);
	}
	return (err);
}

int		return_message_c(char *error, char c, int err)
{
	if (error)
	{
		ft_putstr_fd(error, 1);
		if (c != 0)
		{
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		else
			write(1, "\n", 1);
	}
	return (err);
}
