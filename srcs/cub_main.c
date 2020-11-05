/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:33:49 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 23:35:59 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_text(t_global *env)
{
	env->data.tex = malloc(5 * sizeof(char*));
	env->data.tex[0] = ft_strdup("./assets/ui/menu/menu.xpm");
	env->data.tex[1] = ft_strdup("./assets/ui/menu/menu_p.xpm");
	env->data.tex[2] = ft_strdup("./assets/ui/menu/menu_s.xpm");
	env->data.tex[3] = ft_strdup("./assets/ui/menu/menu_q.xpm");
	env->data.tex[4] = NULL;
}

int		loop(t_global *env)
{
	if (env->op.ceilflooron) //?
	{
		if (env->events.key_on[KEY_F])
			env->op.ceilingandfloor = false;
		else
			env->op.ceilingandfloor = true;
	}
	if (env->op.ceilingandfloor)
		main_floor(env->game, &env->data);
	main_raycast(env->game, &env->data, env->op);
	main_sprite(env->game, &env->data);
	if (env->op.minimap)
		main_map(&env->data, env->game->game);
	control_events(&env->data, &env->game->rc, env->events, &env->op);
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->game->game->img
	, 0, 0);
	xpm_to_gif(env->game, &env->data);
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		loop_bonus(t_global *env)
{
	if (env->op.menu)
		menu_game(env);
	if (env->op.game)
	{
		if (env->op.ceilflooron) //?
		{
			if (env->events.key_on[KEY_F])
			env->op.ceilingandfloor = false;
			else
			env->op.ceilingandfloor = true;
		}
		if (env->op.ceilingandfloor)
			main_floor(env->game, &env->data);
		main_raycast(env->game, &env->data, env->op);
		main_sprite(env->game, &env->data);
		if (env->op.minimap)
			main_map(&env->data, env->game->game);
		control_events(&env->data, &env->game->rc, env->events, &env->op);
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->game->game->img
		, 0, 0);
		if (env->op.minimap)
			mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->map->img,
			0, 0);
		xpm_to_gif(env->game, &env->data);
	}
	mlx_do_sync(env->win.mlx);
	return (0);
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
	mlx_hook(env->win.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &env->events);
	mlx_hook(env->win.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release,
	&env->events);
	mlx_hook(env->win.win, BUTTON_PRESS, BUTTON_PRESS_MASK, button_press,
	&env->events);
	mlx_hook(env->win.win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, button_release,
	&env->events);
	mlx_hook(env->win.win, 17, 0, close_window, env);
	if (env->op.on)
		mlx_loop_hook(env->win.mlx, loop_bonus, env);
	else
		mlx_loop_hook(env->win.mlx, loop, env);
	mlx_loop(env->win.mlx);
	return (0);
}
