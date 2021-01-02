/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:33:49 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:06:12 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		loop(t_global *env)
{
	env->frame.fps++;
	poll_events(&env->events);
	if (get_key(KEY_ESCAPE, &env->events))
		free_cub(env, 0);
	if (env->op.ceilflooron && env->op.ceilingandfloor)
		main_floor(env->game, &env->data);
	main_raycast(env->game, &env->data, env->op);
	main_sprite(env->game, &env->data);
	if (get_key_press(KEY_J, &env->events))
		init_bmp(env);
	if (env->op.minimap)
		main_map(&env->data, env->game->game, &env->game->rc);
	move_player(&env->data, &env->game->rc, &env->events);
	control_events(&env->events, &env->op);
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->game->game->img
	, 0, 0);
	xpm_to_gif(env->game, &env->data);
	main_fps(env, 100, 100, RED);
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		loop_bonus(t_global *env)
{
	env->frame.fps++;
	poll_events(&env->events);
	if (env->op.menu)
		menu_game(env);
	if (env->op.game)
	{
		if (env->op.ceilflooron && env->op.ceilingandfloor)
			main_floor(env->game, &env->data);
		main_raycast(env->game, &env->data, env->op);
		main_sprite(env->game, &env->data);
		if (env->op.minimap)
			main_map(&env->data, env->game->game, &env->game->rc);
		if (!env->op.resume && !env->op.settings)
			move_player(&env->data, &env->game->rc, &env->events);
		control_events(&env->events, &env->op);
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->game->game->img
		, 0, 0);
		if (get_key_press(KEY_J, &env->events))
			init_bmp(env);
		if (env->op.ui)
			mlx_put_image_to_window(env->win.mlx, env->win.win,
			env->main->hud->img, 0, 0);
		if (env->op.minimap)
			mlx_put_image_to_window(env->win.mlx, env->win.win,
			env->main->map->img, 0, 0);
		main_debug(env, RED);
		xpm_to_gif(env->game, &env->data);
	}
	if (env->op.resume)
		resume_game(env);
	if (env->op.settings)
		settings_menu(env);
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_global	*env;

	if (!(env = ft_calloc(1, sizeof(t_global))))
		error_cub("Allocation", env);
	if (init_parse(env, ac, av))
		free_cub(env, 0);
	if (!(env->win.mlx = mlx_init()))
		error_cub("MLX", env);
	init_game(env);
	if (!(env->win.win = mlx_new_window(env->win.mlx, env->data.resx,
	env->data.resy, "Cub3D")))
		error_cub("MLX", env);
	mlx_hook(env->win.win, 2, (1L << 0), key_press, &env->events);
	mlx_hook(env->win.win, 3, (1L << 1), key_release, &env->events);
	mlx_hook(env->win.win, 4, (1L << 2), button_press, &env->events);
	mlx_hook(env->win.win, 5, (1L << 3), button_release, &env->events);
	mlx_hook(env->win.win, 17, 0, close_window, env);
	if (env->op.save)
		start_bmp(env);
	if (env->op.on)
		mlx_loop_hook(env->win.mlx, loop_bonus, env);
	else
		mlx_loop_hook(env->win.mlx, loop, env);
	mlx_loop(env->win.mlx);
	return (0);
}
