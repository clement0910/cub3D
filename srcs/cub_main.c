/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:33:49 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 15:18:29 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	menu_game(t_global *env)
{
	mlx_mouse_get_pos(env->win.win, &env->bonus.cursor.x, &env->bonus.cursor.y);
	if (env->bonus.cursor.x > 630 && env->bonus.cursor.x < 870 && env->bonus.cursor.y > 345 && env->bonus.cursor.y < 490)
	 	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[1]->img, 0, 0);
	else if (env->bonus.cursor.x > 645 && env->bonus.cursor.x < 855 && env->bonus.cursor.y > 520 && env->bonus.cursor.y < 600)
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[2]->img, 0, 0);
	else if (env->bonus.cursor.x > 655 && env->bonus.cursor.x < 845 && env->bonus.cursor.y > 630 && env->bonus.cursor.y < 730)
		close_window(env, env->bonus.cursor.x, env->bonus.cursor.y);	
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[0]->img, 0, 0);
	if (env->bonus.cursor.x > 1440 || env->bonus.cursor.y > 900) //cursor out of map
		mlx_mouse_move(env->win.win, 700, 450);
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->cursor->img, env->bonus.cursor.x, env->bonus.cursor.y);
}

int loop(t_global *env)
{
	mlx_do_sync(env->win.mlx);
	return (0);
}

int loop_bonus(t_global *env)
{
	if (env->bonus.menu)
		menu_game(env);
	mlx_do_sync(env->win.mlx);
	return (0);
}

int main(int ac, char **av)
{
	t_global *env;
	env = malloc(sizeof(t_global)); 
	ft_bzero(env, sizeof(t_global));

	if (!(env->main = malloc(sizeof(t_menu))))
		return (1);
	env->win.mlx = mlx_init();
	env->win.win = mlx_new_window(env->win.mlx, 1440,
	900, "Cub3D");
	if (!(env->main->menu = create_tab_xpm(env->win.mlx, 1440, 900)))
		return (1);
	if (!(env->cursor = create_xpm_image(env->win.mlx, "assets/ui/cursor/cursor.xpm")))
		return (1);
	mlx_mouse_hide();
	mlx_hook(env->win.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &env->events);
	mlx_hook(env->win.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, &env->events); 
	mlx_hook(env->win.win, BUTTON_PRESS, BUTTON_PRESS_MASK, button_press, &env->events);
	mlx_hook(env->win.win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, button_release, &env->events);
	mlx_hook(env->win.win, 17, 0, quit_from_cross, env);
	env->bonus.on = true;
	if (env->bonus.on)
	{
		mlx_loop_hook(env->win.mlx, loop_bonus, env);
		env->bonus.menu = true;
	}
	else
		mlx_loop_hook(env->win.mlx, loop, env);
	mlx_loop(env->win.mlx);
	return (0);
}