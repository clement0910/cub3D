/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:59:51 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 01:22:43 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_window(t_global *env, int x, int y)
{
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->main->menu[3]->img,
	0, 0);
	if (get_button(MOUSE_LEFT, 0, 0, &env->events))
		quit_cub(env);
	mlx_put_image_to_window(env->win.mlx, env->win.win,
	env->cur->img->img, x, y);
}

void	free_image_tab(int n, t_img **tab, void *mlx)
{
	int x;

	x = 0;
	while (x < n)
	{
		free_image(tab[x], mlx);
		x++;
	}
	free(tab);
}

int		quit_from_cross(t_global *env)
{
	quit_cub(env);
	return (0);
}

void	quit_cub(t_global *env)
{
	free(env->data.xpm_no);
	free(env->data.xpm_so);
	free(env->data.xpm_ea);
	free(env->data.xpm_we);
	free(env->data.sprite);
	ft_free_tab(env->data.map);
	free_image_tab(5, env->main->menu, env->win.mlx);
	free_image(env->cur->img, env->win.mlx);
	mlx_destroy_window(env->win.mlx, env->win.win);
	free(env->main);
	free(env->cur);
	free(env);
	exit(0);
}
