/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:57:20 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 22:37:22 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_fps(t_global *env, int x, int y, int color)
{
	char	*str_fps;

	if (env->data.resx < 500 || env->data.resy < 500)
		return ;
	if (!env->op.fps)
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
