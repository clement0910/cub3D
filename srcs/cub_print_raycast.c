/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_raycast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:55:42 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 15:56:15 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_raycast(t_game *game, t_parse *data, t_optis op)
{
	int x;

	x = 0;
	while (x < data->resx)
	{
		init_ray(&game->rc, data, x);
		init_dist(&game->rc, data);
		dda_algo(&game->rc, data);
		start_draw(&game->rc, data);
		if (op.texture)
			draw_tex(game, data, x);
		game->rc.zbuffer[x] = game->rc.pwalld;
		write_rc(game, data, op, x);
		x++;
	}
}

void	write_rc(t_game *game, t_parse *data, t_optis op, int x)
{
	int y;

	y = -1;
	if (op.ceilingandfloor == false)
	{
		while (++y < game->rc.dstart)
			write_pixel(game->game, x, y, data->ceiling.color);
	}
	if (op.texture == false)
	{
		while (game->rc.dstart <= game->rc.dend)
		{
			write_pixel(game->game, x, game->rc.dstart, game->rc.color);
			game->rc.dstart++;
		}
	}
	y = game->rc.dend + 1;
	if (op.ceilingandfloor == false)
	{
		while (y < data->resy)
		{
			write_pixel(game->game, x, y, data->floor.color);
			y++;
		}
	}
}

void	print_square(t_img *img, int color, t_vec2i mapwrite, int ratio)
{
	int		i;
	int		z;
	int		xtmp;

	i = 0;
	z = 0;
	while (i < ratio)
	{
		xtmp = mapwrite.x;
		while (z < ratio)
		{
			write_pixel(img, mapwrite.x, mapwrite.y, color);
			z++;
			mapwrite.x++;
		}
		mapwrite.x = xtmp;
		z = 0;
		i++;
		mapwrite.y++;
	}
}

void	color_sprite(t_game *game, int i)
{
	game->rc.color = game->sprite[game->spriteorder[i]]->
	sprite[game->sprite[game->spriteorder[i]]->xpm]->addr
	[game->rc.tex.y * game->sprite[game->spriteorder[i]]->sprite
	[game->sprite[game->spriteorder[i]]->xpm]->line_length_i + game->rc.tex.x];
}

void	write_pixel(t_img *image, int x, int y, int color)
{
    int		*dst;

	dst = image->addr + (y * (image->line_length / 4) + x);
	*dst = color;
}
