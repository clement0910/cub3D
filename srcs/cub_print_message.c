/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:00:20 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 15:42:22 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	credits_message(bool *help)
{
	*help = true;
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("Cub3D par Clément Sapt (csapt).\n");
	ft_printf("csapt@student.42lyon.fr\n");
	ft_putstr_fd(RESET_ERROR, 1);
	ft_printf("Un grand merci à Tryrun pour son aide sur le projet.\n");
	ft_printf("Et merci aussi à tous ceux qui m'ont aidé de près ou de loin à \
réussir ce projet: Agathe, Nicolas, Killian, Terry, Yiching, Elyas, Romain, \
Maël, Salomé, Ludo...\n");
}

void	help_message(bool *help)
{
	*help = true;
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("Cub3D par Clément Sapt (csapt)\n");
	ft_putstr_fd(RESET_ERROR, 1);
	ft_printf("Launch the game with ./Cub3D map.cub\n");
	ft_printf("Then you can add an option:\n");
	ft_printf(" - Use --help for see the commands.\n");
	ft_printf(" - Use --save to make a screenshot of the game.\n");
	ft_printf(" - Use --ignore to ignore warning message.\n");
	ft_printf(" - Use --data to see parsing data.\n");
}
