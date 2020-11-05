/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:34:13 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 11:14:48 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray_so_no(t_parse *data, t_game *game)
{
	if (data->orientation == 'N')
	{
		game->rc.plane.x = 0;
		game->rc.plane.y = 0.66;
		game->rc.dir.x = -1;
		game->rc.dir.y = 0;
	}
	if (data->orientation == 'S')
	{
		game->rc.plane.x = 0;
		game->rc.plane.y = -0.66;
		game->rc.dir.x = 1;
		game->rc.dir.y = 0;
	}
}

void	init_ray_ea_we(t_parse *data, t_game *game)
{
	if (data->orientation == 'W')
	{
		game->rc.plane.x = -0.66;
		game->rc.plane.y = 0;
		game->rc.dir.x = 0;
		game->rc.dir.y = -1;
	}
	if (data->orientation == 'E')
	{
		game->rc.plane.x = 0.66;
		game->rc.plane.y = 0;
		game->rc.dir.x = 0;
		game->rc.dir.y = 1;
	}
}

void	init_precalculated_rc(t_parse *data, t_game *game)
{
	game->rc.pre1 = data->resy * 128;
	game->rc.pre2 = data->resx / 2;
	game->rc.pre3 = data->resy / 2;
	game->rc.pre4 = data->resy - 1;
	game->rc.pre5 = data->resx - 1;
}

void	init_raystruct(t_parse *data, t_game *game)
{
	init_ray_so_no(data, game);
	init_ray_ea_we(data, game);
	init_precalculated_rc(data, game);
}
