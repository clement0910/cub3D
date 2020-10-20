/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:59:51 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:21:34 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_raycast(t_global *env)
{
	int x;

	x = 0;
	while (x < env->data.resx)
	{
		write_ray(env->rc, env->data, x);
		initialdist(env->rc, env->data);
		dda_algo(env->rc, env->data);
		start_draw(env->rc, env->data);
		write_rc(env->game, env->rc, x, env->data, env->op);
		x++;
	}
}

void	write_rc(t_img *img, t_raycast *rc, int x, t_parse data, t_options op)
{
	int y;

	y = 0;
	if (op.ceilingandfloor == false)
		while (y++ < rc->dstart)
			write_pixel(img, x, y, data.ceiling.color);
	if (op.texture == false)
		while (rc->dstart++ <= rc->dend)
			write_pixel(img, x, rc->dstart, rc->color);
	y = rc->dend + 1;
	if (op.ceilingandfloor == false)
		while (y++ < data.resy)
			write_pixel(img, x, y, data.floor.color);
}

void	write_pixel(t_img *image, int x, int y, int color)
{
    int		*dst;
	//Protect value and check if x and y are in image.
	dst = image->addr + (y * (image->line_length / 4) + x);
	*dst = color;
}

void	quit_button(t_global *env, int x, int y)
{
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[3]->img,
	0, 0);
	if (get_button(MOUSE_LEFT, 0, 0, &env->events))
		quit_cub(env);
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->cur->img->img, x, y);
}

void	start_game(t_global *env, int x, int y)
{
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[1]->
	img, 0, 0);
	if (get_button(MOUSE_LEFT, 0, 0, &env->events))
	{
		env->op.game = true;
		env->opb.menu = false;
		//free menu !!
	}
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->cur->img->img, x, y);
}

int		close_window(t_global *env)
{
	quit_cub(env);
	return (0);
}

void	quit_cub(t_global *env)
{
	free(env->data.xpm_no);
	free(env->data.xpm_so);
	free(env->data.xpm_ea);
	free(env->data.xpm_we);
	free(env->data.sprite);
	ft_free_tab(env->data.map);
	free_image_tab(5, env->main->menu, env->win.mlx);
	free_image(env->game, env->win.mlx);
	free_image(env->cur->img, env->win.mlx);
	mlx_destroy_window(env->win.mlx, env->win.win);
	free(env->rc);
	free(env->main);
	free(env->cur);
	free(env);
	exit(0);
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
