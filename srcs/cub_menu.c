/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:06:49 by csapt             #+#    #+#             */
/*   Updated: 2020/10/22 18:57:33 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	menu_game(t_global *env)
{
	mlx_mouse_get_pos(env->win.win, &env->main->cur->pos.x,
	&env->main->cur->pos.y);
	if (env->main->cur->pos.x > 630 && env->main->cur->pos.x < 870 &&
	env->main->cur->pos.y > 345 && env->main->cur->pos.y < 490)
		start_game(env, env->main->cur->pos.x, env->main->cur->pos.y);
	else if (env->main->cur->pos.x > 645 && env->main->cur->pos.x < 855 &&
	env->main->cur->pos.y > 520 && env->main->cur->pos.y < 600)
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[2]->
		img, 0, 0);
	else if (env->main->cur->pos.x > 655 && env->main->cur->pos.x < 845 &&
		env->main->cur->pos.y > 630 && env->main->cur->pos.y < 730)
		quit_button(env, env->main->cur->pos.x, env->main->cur->pos.y);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[0]->
		img, 0, 0);
	mlx_put_image_to_window(env->win.mlx, env->win.win, 
	env->main->cur->img->img, env->main->cur->pos.x, env->main->cur->pos.y);
}

void	start_game(t_global *env, int x, int y)
{
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[1]->
	img, 0, 0);
	if (get_button(MOUSE_LEFT, 0, 0, &env->events))
	{
		env->op.game = true;
		env->op.menu = false;
		//free menu !!
	}
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->main->cur->img->img, x, y);
}

void	quit_button(t_global *env, int x, int y)
{
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[3]->img,
	0, 0);
	if (get_button(MOUSE_LEFT, 0, 0, &env->events))
		free_cub(env, 0);
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->main->cur->img->img, x, y);
}
