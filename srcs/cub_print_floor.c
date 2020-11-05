/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 00:31:02 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 11:20:16 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calcul_floor_step(t_game *game, t_parse *data, int y)
{
	game->rc.ray0.x = game->rc.dir.x - game->rc.plane.x;
	game->rc.ray0.y = game->rc.dir.y - game->rc.plane.y;
	game->rc.ray1.x = game->rc.dir.x + game->rc.plane.x;
	game->rc.ray1.y = game->rc.dir.y + game->rc.plane.y;
	game->rc.posycenter = y - data->resy / 2;
	game->rc.posz = 0.5 * data->resy;
	game->rc.rowdistance = game->rc.posz / game->rc.posycenter;
	game->rc.floorstep.x = game->rc.rowdistance * (game->rc.ray1.x -
	game->rc.ray0.x) / data->resx;
	game->rc.floorstep.y = game->rc.rowdistance * (game->rc.ray1.y -
	game->rc.ray0.y) / data->resx;
	game->rc.floor.x = data->player.x + game->rc.rowdistance * game->rc.ray0.x;
	game->rc.floor.y = data->player.y + game->rc.rowdistance * game->rc.ray0.y;
}

void	calcul_floor(t_game *game)
{
	game->rc.cell.x = (int)game->rc.floor.x;
	game->rc.cell.y = (int)game->rc.floor.y;
	game->rc.tx = (int)(game->ceiling->width * (game->rc.floor.x -
	game->rc.cell.x)) & (game->ceiling->width - 1);
	game->rc.ty = (int)(game->ceiling->height * (game->rc.floor.y -
	game->rc.cell.y)) & (game->ceiling->height - 1);
	game->rc.floor.x += game->rc.floorstep.x;
	game->rc.floor.y += game->rc.floorstep.y;
}

void	main_floor(t_game *game, t_parse *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->resy)
	{
		calcul_floor_step(game, data, y);
		x = 0;
		while (x < data->resx)
		{
			calcul_floor(game);
			write_pixel(game->game, x, y, game->floor->addr
			[game->rc.ty * (game->floor->line_length_i) + game->rc.tx]);
			write_pixel(game->game, x, data->resy - y - 1, game->ceiling->addr
			[game->rc.ty * (game->ceiling->line_length_i) + game->rc.tx]);
			x++;
		}
		y++;
	}
}
