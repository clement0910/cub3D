/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:57:20 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 16:38:37 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_fps(t_global *env, int x, int y, int color)
{
	char	*str_fps;

	if (env->data.resx < 500 || env->data.resy < 500)
		return ;
	if (env->op.fps)
	{
		if (!(str_fps = ft_itoa(env->frame.lastfps)))
			error_cub("Allocation FPS", env);
		mlx_string_put(env->win.mlx, env->win.win, x, y, color, str_fps);
		free(str_fps);
	}
	if (timer_get_seconds(&env->frame.timer) >= 1)
	{
		env->frame.lastfps = env->frame.fps;
		env->frame.fps = 0;
		timer_restart(&env->frame.timer);
	}
}

void	print_debug_tex(t_global *env, int color)
{
	if (env->op.texture)
	{
		mlx_string_put(env->win.mlx, env->win.win, 30, 50, color,
		env->data.debug[NO]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 70, color,
		env->data.debug[SO]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 90, color,
		env->data.debug[EA]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 110, color,
		env->data.debug[WE]);
	}
	else
	{
		mlx_string_put(env->win.mlx, env->win.win, 30, 50, color,
		env->data.debug[4]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 70, color,
		env->data.debug[5]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 90, color,
		env->data.debug[6]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 110, color,
		env->data.debug[7]);
	}
}

void	print_debug_fps(t_global *env, int color)
{
	char *str_fps;
	char *tmp;

	if (!(str_fps = ft_itoa(env->frame.lastfps)))
		error_cub("Allocation FPS", env);
	if (!(tmp = ft_strjoin("FPS :", str_fps)))
	{
		free(str_fps);
		error_cub("Allocation FPS", env);
	}
	mlx_string_put(env->win.mlx, env->win.win, 30, 30, color, tmp);
	free(tmp);
	free(str_fps);
}

void	print_debug_floorceiling(t_global *env, int color)
{
	if (env->op.ceilingandfloor)
	{
		mlx_string_put(env->win.mlx, env->win.win, 30, 170, color,
		env->data.debug[9]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 190, color,
		env->data.debug[10]);
	}
	else
	{
		mlx_string_put(env->win.mlx, env->win.win, 30, 170, color,
		env->data.debug[11]);
		mlx_string_put(env->win.mlx, env->win.win, 30, 190, color,
		env->data.debug[12]);
	}
}

void	main_debug(t_global *env, int color)
{
	char	*tmp;

	if (env->op.fps)
	{
		print_debug_fps(env, color);
		//print_debug_tex(env, color);
		mlx_string_put(env->win.mlx, env->win.win, 30, 130, color,
		env->data.debug[8]);
		if (!(tmp = str_from_int(env->data.player.x,
		env->data.player.y, "POS:")))
			error_cub("Allocation FPS", env);
		mlx_string_put(env->win.mlx, env->win.win, 30, 150, color, tmp);
		free(tmp);
		print_debug_floorceiling(env, color);
	}
	if (timer_get_seconds(&env->frame.timer) >= 1)
	{
		env->frame.lastfps = env->frame.fps;
		env->frame.fps = 0;
		timer_restart(&env->frame.timer);
	}
}
