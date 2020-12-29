/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:33:49 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 22:37:44 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		loop(t_global *env)
{
	env->frame.fps++;
	poll_events(&env->events);
	if (get_key(KEY_ESCAPE, &env->events))
		free_cub(env, 0);
	if (env->op.ceilflooron)
	{
		if (get_key_press(KEY_F, &env->events))
			env->op.ceilingandfloor = !env->op.ceilingandfloor;
	}
	if (env->op.ceilingandfloor)
		main_floor(env->game, &env->data);
	main_raycast(env->game, &env->data, env->op);
	main_sprite(env->game, &env->data);
	if (get_key_press(KEY_J, &env->events))
	{
		init_bmp(env);
		printf("SAVE DEPUIS J\n");
	}
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
	poll_events(&env->events);
	if (env->op.menu)
		menu_game(env);
	if (env->op.game)
	{
		if (env->op.ceilflooron)
		{
			if (get_key_press(KEY_F, &env->events))
				env->op.ceilingandfloor = !env->op.ceilingandfloor;
		}
		if (env->op.ceilingandfloor)
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
		{
			init_bmp(env);
			printf("SAVE DEPUIS J\n");
		}
		if (env->op.minimap)
			mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->map->img,
			0, 0);
		xpm_to_gif(env->game, &env->data);
	}
	if (env->op.resume)
		resume_game(env);
	if (env->op.settings)
		settings_menu(env);
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		check_options(int ac, char **av, t_optis *op)
{
	if (ac > 3 || ac < 2)
	{
		ft_putendl_fd("Use ./Cub3D --help for more info.", 1);
		return (1);
	}
	if (ft_strncmp(av[1], "--help", 6) == 0)
	{
		ft_putendl_fd("Message", 1);
		return (1);
	}
	if (!av[2])
		return (0);
	if (ft_strncmp(av[2], "--data", 6) == 0)
		op->data = true;
	else if (ft_strncmp(av[2], "--save", 6) == 0)
		op->save = true;
	else if (ft_strncmp(av[2], "--ignore", 8) == 0)
		op->ignore = true;
	else
	{
		ft_putendl_fd("Use ./Cub3D --help for more info.", 1);
		return (1);
	}
	return (0);
}

void	write_pixel(t_img *image, int x, int y, int color)
{
    int		*dst;

	dst = image->addr + (y * (image->line_length / 4) + x);
	*dst = color;
}


int		main(int ac, char **av)
{
	t_global	*env;

	if (!(env = ft_calloc(1, sizeof(t_global))))
		error_cub("Allocation", env);
	init_parse(env, ac, av);
	env->win.mlx = mlx_init();
	init_game(env);
	init_raystruct(&env->data, env->game);
	env->win.win = mlx_new_window(env->win.mlx, env->data.resx,
	env->data.resy, "Cub3D");
	env->op.texture = true;
	mlx_hook(env->win.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &env->events);
	mlx_hook(env->win.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release,
	&env->events);
	mlx_hook(env->win.win, BUTTON_PRESS, BUTTON_PRESS_MASK, button_press,
	&env->events);
	mlx_hook(env->win.win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, button_release,
	&env->events);
	mlx_hook(env->win.win, 17, 0, close_window, env);
	timer_restart(&env->frame.timer);
	if (env->op.save)
	{
		start_bmp(env);
		return (0);
	}
	if (env->op.on)
		mlx_loop_hook(env->win.mlx, loop_bonus, env);
	else
		mlx_loop_hook(env->win.mlx, loop, env);
	mlx_loop(env->win.mlx);
	return (0);
}
