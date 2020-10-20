/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:33:49 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:21:48 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_raystruct(t_global *env)
{
	env->data.player.x = 16;
	env->data.player.y = 16;
	env->rc->dir.x = -1;
	env->rc->dir.y = 0;
	env->rc->plane.x = 0;
	env->rc->plane.y = 0.66;
}

void	menu_game(t_global *env)
{
	mlx_mouse_get_pos(env->win.win, &env->cur->pos.x, &env->cur->pos.y);
	if (env->cur->pos.x > 630 && env->cur->pos.x < 870 && env->cur->pos.y >
		345 && env->cur->pos.y < 490)
		start_game(env, env->cur->pos.x, env->cur->pos.y);
	else if (env->cur->pos.x > 645 && env->cur->pos.x < 855 && env->cur->pos.y >
		520 && env->cur->pos.y < 600)
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[2]->
		img, 0, 0);
	else if (env->cur->pos.x > 655 && env->cur->pos.x < 845 && env->cur->pos.y >
		630 && env->cur->pos.y < 730)
		quit_button(env, env->cur->pos.x, env->cur->pos.y);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[0]->
		img, 0, 0);
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->cur->img->img,
	env->cur->pos.x, env->cur->pos.y);
}

int		loop(t_global *env)
{
	main_raycast(env);
	control_events(&env->data, env->rc, env->events);
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->game->img, 0, 0);
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		loop_bonus(t_global *env)
{
	if (env->opb.menu)
		menu_game(env);
	if (env->op.game)
	{
		main_raycast(env);
		control_events(&env->data, env->rc, env->events);
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->game->img, 0, 0);
	}
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_global	*env;
	int			fd;

	fd = open(av[1], O_RDONLY);
	env = malloc(sizeof(t_global));
	ft_bzero(env, sizeof(t_global));
	if (cub_global_parse(fd, &env->data, env->win.mlx) == 1)
	{
		printf("PARSE ERROR\n");
		return (1);
	}
	close(fd);
	if (env->data.resx == 1440 && env->data.resy == 900)
	{
		if (!(env->main = malloc(sizeof(t_menu))))
			return (1);
		if (!(env->cur = malloc(sizeof(t_cursor))))
			return (1);
		env->opb.on = true;
	}
	if (!(env->rc = malloc(sizeof(t_raycast))))
		return(1);
	init_raystruct(env);
	env->win.mlx = mlx_init();
	env->win.win = mlx_new_window(env->win.mlx, 1440,
	900, "Cub3D");
	if (!(env->main->menu = create_tab_xpm(env->win.mlx, 1440, 900)))
		return (1);
	if (!(env->cur->img = create_xpm_image(env->win.mlx, "assets/ui/cursor/cursor.xpm")))
		return (1);
	if (!(env->game = create_image(env->win.mlx, env->data.resx, env->data.resy)))
		return (1);
	mlx_mouse_hide();
	mlx_hook(env->win.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &env->events);
	mlx_hook(env->win.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, &env->events);
	mlx_hook(env->win.win, BUTTON_PRESS, BUTTON_PRESS_MASK, button_press, &env->events);
	mlx_hook(env->win.win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, button_release, &env->events);
	mlx_hook(env->win.win, 17, 0, close_window, env);
	if (env->opb.on)
	{
		mlx_loop_hook(env->win.mlx, loop_bonus, env);
		env->opb.menu = true;
	}
	else
		mlx_loop_hook(env->win.mlx, loop, env);
	mlx_loop(env->win.mlx);
	return (0);
}
