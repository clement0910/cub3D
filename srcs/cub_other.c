/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:59:51 by csapt             #+#    #+#             */
/*   Updated: 2020/10/26 17:47:43 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_raycast(t_game *game, t_parse data, t_options op)
{
	int x;

	x = 0;
	while (x < data.resx)
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

void	init_sprite(t_global *env)
{
	env->data.info[0].x = 10;
	env->data.info[0].y = 10;
	env->data.info[1].x = 17;
	env->data.info[1].y = 17;
}

void	write_rc(t_game *game, t_parse data, t_options op, int x)
{
	int y;

	y = -1;
	if (op.ceilingandfloor == false)
		while (y++ < game->rc.dstart)
			write_pixel(game->game, x, y, data.ceiling.color);
	game->rc.dstart -= 1;
	if (op.texture == false)
		while (game->rc.dstart++ < game->rc.dend)
			write_pixel(game->game, x, game->rc.dstart, game->rc.color);
	y = game->rc.dend;
	if (op.ceilingandfloor == false)
		while (y++ < data.resy - 1)
			write_pixel(game->game, x, y, data.floor.color);
	//rc->dstart =- 1; GIANT MODE;
	//Check this func
}

void	write_pixel(t_img *image, int x, int y, int color)
{
    int		*dst;
	//Protect value and check if x and y are in image.
	dst = image->addr + (y * (image->line_length / 4) + x);
	*dst = color;
}

int		close_window(t_global *env)
{
	free_cub(env, 0);
	return (0);
}

void	ft_free_static_tab(char **tab, int size)
{
	int x;

	x = 0;
	if (!tab)
		return;
	if (size == 0)
		return ;
	while (x < size)
	{
		if (tab)
			free(tab[x]);
		x++;
	}
}

void	xpm_to_gif(t_game *game, t_parse data)
{
	int x;

	x = 0;
	while (x < data.nbsprite)
	{
		if (game->sprite[x]->xpm == (game->sprite[x]->nsprite - 1))
			game->sprite[x]->xpm = 0;
		if (game->sprite[x]->nsprite > 1)
			game->sprite[x]->xpm++;
		x++;
	}
}

void	control_events(t_parse *data, t_raycast *rc, t_keys events)
{
	if (get_key(KEY_W, &events))
		move_forward(data, rc, 0.08);
	if (get_key(KEY_SHIFT_LEFT, &events))
		move_forward(data, rc, 0.12);
	if (get_key(KEY_S, &events))
		move_backward(data, rc, 0.08);
	if (get_key(KEY_A, &events))
		move_left(data, rc, 0.08);
	if (get_key(KEY_D, &events))
		move_right(data, rc, 0.08);
	if (get_key(KEY_LEFT, &events))
		rotate(rc, 0.08);
	if (get_key(KEY_RIGHT, &events))
		rotate(rc, -0.08);
}
