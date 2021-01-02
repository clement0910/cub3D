/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:35:03 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 15:54:53 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_bonus(t_global *env)
{
	if (!(env->main = ft_calloc(1, sizeof(t_menu))))
		error_cub("Allocation", env);
	env->op.on = true;
	if (!(env->main->cur = ft_calloc(1, sizeof(t_cursor))))
		error_cub("Allocation", env);
	if (init_xpm(&env->data))
		error_cub("Allocation", env);
	if (create_xpm_bonus(env))
		error_cub("Allocation", env);
	if ((init_debugstr(&env->data)))
		error_cub("Allocation", env);
	env->op.menu = true;
	mlx_mouse_hide();
}

int		create_xpm_bonus(t_global *env)
{
	if (!(env->main->menu = create_tab_xpm(env->win.mlx, 4, env->data.tex)))
		return (1);
	if (!(env->main->resume = create_tab_xpm(env->win.mlx, 5,
	env->data.resume)))
		return (1);
	if (!(env->main->settings = create_tab_xpm(env->win.mlx, 2,
	env->data.settings)))
		return (1);
	if (!(env->main->cur->img = create_xpm_image(env->win.mlx,
	"assets/ui/cursor/cursor.xpm")))
		return (1);
	if (!(env->main->map = create_xpm_image(env->win.mlx,
	"assets/ui/map/cardinal-point.xpm")))
		return (1);
	if (!(env->main->on = create_xpm_image(env->win.mlx,
	"assets/ui/settings/whitepixel.xpm")))
		return (1);
	return (0);
}

void	init_game(t_global *env)
{
	check_resolution(&env->data.resx, &env->data.resy, env->win.mlx, &env->op);
	if (!(env->game = ft_calloc(1, sizeof(t_game))))
		error_cub("Allocation", env);
	if (!(env->game->game = create_image(env->win.mlx, env->data.resx,
		env->data.resy)))
		error_cub("Allocation", env);
	if (env->data.floor.xpm != NULL)
		if (!(env->game->floor = create_xpm_image(env->win.mlx,
		env->data.floor.xpm)))
			error_cub("Allocation", env);
	if (env->data.ceiling.xpm != NULL)
		if (!(env->game->ceiling = create_xpm_image(env->win.mlx,
		env->data.ceiling.xpm)))
			error_cub("Allocation", env);
	ft_bzero(&env->game->rc, sizeof(env->game->rc));
	if (!(env->game->textures = create_tab_xpm(env->win.mlx, 4, env->data.xpm)))
		error_cub("Allocation", env);
	init_sprites(env);
	if (env->data.resx == 1440 && env->data.resy == 900 && !env->op.save)
		init_bonus(env);
	init_raystruct(&env->data, env->game);
	env->op.texture = true;
	if (env->op.ceilflooron)
		env->op.ceilingandfloor = true;
}

void	init_sprites(t_global *env)
{
	if (!(env->game->rc.zbuffer = malloc(env->data.resx * sizeof(double))))
		error_cub("Allocation", env);
	if (!(env->game->spriteorder = malloc(env->data.nbsprite * sizeof(int))))
		error_cub("Allocation", env);
	if (!(env->game->sprite = create_sprite_tab(env->win.mlx,
	env->data.s_map, env->data.nbsprite)))
		error_cub("Allocation", env);
}
