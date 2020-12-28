/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_resume.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:35:58 by csapt             #+#    #+#             */
/*   Updated: 2020/12/27 16:57:06 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	resume_game(t_global *env)
{
	mlx_mouse_get_pos(env->win.win, &env->main->cur->pos.x,
	&env->main->cur->pos.y);
	if (env->main->cur->pos.x > 615 && env->main->cur->pos.x < 825 &&
	env->main->cur->pos.y > 285 && env->main->cur->pos.y < 410)
		start_button(env, env->main->cur->pos.x, env->main->cur->pos.y);
	else if (env->main->cur->pos.x > 617 && env->main->cur->pos.x < 825 &&
	env->main->cur->pos.y > 432 && env->main->cur->pos.y < 510)
		settings_button(env, env->main->cur->pos.x, env->main->cur->pos.y);
	else if (env->main->cur->pos.x > 630 && env->main->cur->pos.x < 809 &&
		env->main->cur->pos.y > 535 && env->main->cur->pos.y < 619)
		quit_button(env, env->main->cur->pos.x, env->main->cur->pos.y);
	else if (env->main->cur->pos.x > 1255 && env->main->cur->pos.x < 1315 &&
		env->main->cur->pos.y > 50 && env->main->cur->pos.y < 110)
		screen_button(env, env->main->cur->pos.x, env->main->cur->pos.y);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win,
		env->main->resume[0]->img, 0, 0);
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->main->cur->img->img, env->main->cur->pos.x, env->main->cur->pos.y);
}

void	screen_button(t_global *env, int x, int y)
{
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->resume[4]->
	img, 0, 0);
	if (get_button(MOUSE_LEFT, 0, 0, &env->events))
		init_bmp(env);
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->main->cur->img->img, x, y);
}
