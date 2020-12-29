/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:14:53 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 10:13:17 by csapt            ###   ########lyon.fr   */
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
			env->op.texture = true;
	}
	if (env->main->cur->pos.x > 946 && env->main->cur->pos.x < 1018 &&
	env->main->cur->pos.y > 672 && env->main->cur->pos.y < 744)
	{
		if (get_button(MOUSE_LEFT, 0, 0, &env->events))
			env->op.texture = false;
	}
	if (env->op.texture == true)
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 904, 729);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->on->img, 976, 729);
}
