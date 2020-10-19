/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:33:49 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 17:36:19 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	menu_game(t_global *env)
{
	mlx_mouse_get_pos(env->win.win, &env->cur->pos.x, &env->cur->pos.y);
	if (env->cur->pos.x > 630 && env->cur->pos.y < 870 && env->cur->pos.y >
		345 && env->cur->pos.y < 490)
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[1]->
		img, 0, 0);
	else if (env->cur->pos.x > 645 && env->cur->pos.y < 855 && env->cur->pos.y >
		520 && env->cur->pos.y < 600)
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[2]->
		img, 0, 0);
	else if (env->cur->pos.x > 655 && env->cur->pos.x < 845 && env->cur->pos.y >
		630 && env->cur->pos.y < 730)
		close_window(env, env->cur->pos.x, env->cur->pos.y);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[0]->
		img, 0, 0);
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->cur->img->img,
	env->cur->pos.x, env->cur->pos.y);
}

int		loop(t_global *env)
{
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		loop_bonus(t_global *env)
{
	if (env->opb.menu)
		menu_game(env);
	mlx_do_sync(env->win.mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_global	*env;

	env = malloc(sizeof(t_global));
	ft_bzero(env, sizeof(t_global));
	if (!(env->main = malloc(sizeof(t_menu))))
		return (1);
	if (!(env->cur = malloc(sizeof(t_cursor))))
		return (1);
	env->win.mlx = mlx_init();
	env->win.win = mlx_new_window(env->win.mlx, 1440,
	900, "Cub3D");
	if (!(env->main->menu = create_tab_xpm(env->win.mlx, 1440, 900)))
		return (1);
	if (!(env->cur->img = create_xpm_image(env->win.mlx, "assets/ui/cursor/cursor.xpm")))
		return (1);
	mlx_mouse_hide();
	mlx_hook(env->win.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &env->events);
	mlx_hook(env->win.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, &env->events);
	mlx_hook(env->win.win, BUTTON_PRESS, BUTTON_PRESS_MASK, button_press, &env->events);
	mlx_hook(env->win.win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, button_release, &env->events);
	mlx_hook(env->win.win, 17, 0, quit_from_cross, env);
	env->opb.on = true;
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
