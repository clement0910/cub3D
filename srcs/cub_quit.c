/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:19:21 by csapt             #+#    #+#             */
/*   Updated: 2020/10/28 14:34:11 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_cub(char *error, t_global *env)
{
	if (error)
		print_error(error, false);
	if (env)
		free_cub(env, 1);
	exit(EXIT_FAILURE);
}

void	print_error(char *error, bool warn)
{
	if (warn)
	{
		ft_putstr_fd(ORANGE_ERROR, 1);
		ft_putendl_fd("WARNING !", 1);
		ft_putendl_fd(error, 1);
		ft_putstr_fd(RESET_ERROR, 1);
	}
	else
	{
		ft_putstr_fd(RED_ERROR, 1);
		ft_putstr_fd(error, 1);
		ft_putendl_fd(" Error !", 1);
		ft_putstr_fd(RESET_ERROR, 1);
	}
}

void	*return_message(char *error, char *details)
{
	if (error)
	{
		ft_putstr_fd(error, 1);
		if (details)
			ft_putendl_fd(details, 1);
		else
			write(1, "\n", 1);
	}
	return (NULL);
}

int		return_message_int(char *error, char *details, int err)
{
	if (error)
	{
		ft_putstr_fd(error, 1);
		if (details)
			ft_putendl_fd(details, 1);
		else
			write(1, "\n", 1);
	}
	return (err);
}

void	free_parsing(t_parse *data)
{
	if (!data)
		return ;
	free_spritei(data->s_info, data->nbspritei);
	ft_free_static_tab(data->xpm, 4);
	free(data->floor.xpm);
	free(data->ceiling.xpm);
	free(data->symbol);
	free(data->s_map);
}

void	free_cub(t_global *env, int ret)
{
	free_parsing(&env->data);
	ft_free_tab(env->data.map);
	if (env->op.on)
	{
		free_image_tab(4, env->main->menu, env->win.mlx);
		if (env->main->cur)
			free_image(env->main->cur->img, env->win.mlx);
	}
	if (env->game)
	{
		free_image(env->game->game, env->win.mlx);
		free_image(env->game->ceiling, env->win.mlx);
		free_image(env->game->floor, env->win.mlx);
		free(env->game->rc.zbuffer);
		free_image_tab(4, env->game->textures, env->win.mlx);
		free_sprite_tab(env->game->sprite, env->win.mlx, env->data.nbsprite);
		mlx_destroy_window(env->win.mlx, env->win.win);
	}
	if (env->op.on)
	{
		ft_free_tab(env->data.tex);
		free(env->main->cur);
		free(env->main);
	}
	free(env->game);
	free(env);
	// while (1)
	// 	;
	exit(ret);
}
