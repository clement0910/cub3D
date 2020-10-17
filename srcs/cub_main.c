/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:33:49 by csapt             #+#    #+#             */
/*   Updated: 2020/10/17 15:25:32 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void func(t_global *env)
{
	int x;
	int y;
	mlx_mouse_get_pos(env->win.win, &x, &y);
	//printf("x: %d| y: %d\n", x, y);
//	Coordoonne button play: 630x 870x 345y 490y
	//	settings: 645x 855x 520y 600y
	//		stop 655x 845x 630y 730y
	if (x > 630 && x < 870 && y > 345 && y < 490)
	 	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[1]->img, 0, 0);
	else if (x > 645 && x < 855 && y > 520 && y < 600)
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[2]->img, 0, 0);
	else if (x > 655 && x < 845 && y > 630 && y < 730)
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[3]->img, 0, 0);
	else
		mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[0]->img, 0, 0);
}
int loop(t_global *env)
{
	func(env);
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
	mlx_loop_hook(env->win.mlx, loop, env);
	mlx_loop(env->win.mlx);
	return (0);
}