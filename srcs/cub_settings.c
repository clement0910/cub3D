/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:14:53 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:22:16 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_menu(t_global *env)
{
	mlx_mouse_get_pos(env->win.win, &env->main->cur->pos.x,
	&env->main->cur->pos.y);
	if (env->main->cur->pos.x > 41 && env->main->cur->pos.x < 166 &&
	env->main->cur->pos.y > 38 && env->main->cur->pos.y < 158)
		return_settings(env);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->settings[0]->img, 0, 0);
	lowcub_settings(env);
	debug_settings(env);
	hud_settings(env);
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->main->cur->img->img, env->main->cur->pos.x, env->main->cur->pos.y);
}

void	return_settings(t_global *env)
{
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->settings[1]->
	img, 0, 0);
	if (get_button(MOUSE_LEFT, 0, 0, &env->events))
	{
		if (env->op.game)
			env->op.resume = true;
		else
			env->op.menu = true;
		env->op.settings = false;
	}
}

void	lowcub_settings(t_global *env)
{
	if (env->main->cur->pos.x > 872 && env->main->cur->pos.x < 945 &&
	env->main->cur->pos.y > 672 && env->main->cur->pos.y < 744)
	{
		if (get_button(MOUSE_LEFT, 0, 0, &env->events))
		{
			env->op.ceilingandfloor = false;
			env->op.texture = false;
		}
	}
	if (env->main->cur->pos.x > 946 && env->main->cur->pos.x < 1018 &&
	env->main->cur->pos.y > 672 && env->main->cur->pos.y < 744)
	{
		if (get_button(MOUSE_LEFT, 0, 0, &env->events))
		{
			env->op.ceilingandfloor = true;
			env->op.texture = true;
		}
	}
	if (env->op.texture == false && env->op.ceilingandfloor == false)
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 904, 729);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 976, 729);
}

void	debug_settings(t_global *env)
{
	if (env->main->cur->pos.x > 872 && env->main->cur->pos.x < 945 &&
	env->main->cur->pos.y > 495 && env->main->cur->pos.y < 567)
	{
		if (get_button(MOUSE_LEFT, 0, 0, &env->events))
			env->op.fps = true;
	}
	if (env->main->cur->pos.x > 946 && env->main->cur->pos.x < 1018 &&
	env->main->cur->pos.y > 495 && env->main->cur->pos.y < 567)
	{
		if (get_button(MOUSE_LEFT, 0, 0, &env->events))
			env->op.fps = false;
	}
	if (env->op.fps == true)
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 904, 552);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 976, 552);
}

void	hud_settings(t_global *env)
{
	if (env->main->cur->pos.x > 872 && env->main->cur->pos.x < 945 &&
	env->main->cur->pos.y > 585 && env->main->cur->pos.y < 655)
	{
		if (get_button(MOUSE_LEFT, 0, 0, &env->events))
			env->op.ui = false;
	}
	if (env->main->cur->pos.x > 946 && env->main->cur->pos.x < 1018 &&
	env->main->cur->pos.y > 585 && env->main->cur->pos.y < 655)
	{
		if (get_button(MOUSE_LEFT, 0, 0, &env->events))
			env->op.ui = true;
	}
	if (env->op.ui == false)
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 904, 642);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 976, 642);	
}
