/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:35:03 by csapt             #+#    #+#             */
/*   Updated: 2020/11/04 17:44:59 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_options(int ac, char **av, t_global *env)
{
	if (ac > 3 || ac < 2)
	{
		ft_putendl_fd("Use ./Cub3D --help for more info.", 1);
		error_cub("Command", env);
	}
	if (ft_strncmp(av[1], "--help", 6) == 0)
	{
		ft_putendl_fd("Message", 1);
		error_cub("Command", env);
	}
	if (!av[2])
		return ;
	if (ft_strncmp(av[2], "--debug", 7) == 0)
		env->op.debug = true;
	else if (ft_strncmp(av[2], "--save", 6) == 0)
		env->op.save = true;
	else if (ft_strncmp(av[2], "--ignore", 8) == 0)
		env->op.ignore = true;
	else
	{
		ft_putendl_fd("Use ./Cub3D --help for more info.", 1);
		error_cub("Command", env);
	}
}

void	init_bonus(t_global *env)
{
	if (!(env->main = ft_calloc(1, sizeof(t_menu))))
		error_cub("Allocation", env);
	env->op.on = true;
	if (!(env->main->cur = ft_calloc(1, sizeof(t_cursor))))
		error_cub("Allocation", env);
	init_text(env);
	if (!(env->main->menu = create_tab_xpm(env->win.mlx, 4, env->data.tex)))
		error_cub("Allocation", env);
	if (!(env->main->cur->img = create_xpm_image(env->win.mlx, "assets/ui/cursor/cursor.xpm")))
		error_cub("Allocation", env);
	env->op.menu = true;
	mlx_mouse_hide();
}

void	init_game(t_global *env)
{
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
	if (!(env->game->rc.zbuffer = malloc(env->data.resx * sizeof(double))))
		error_cub("Allocation", env);
	if (!(env->game->textures = create_tab_xpm(env->win.mlx, 4, env->data.xpm)))
		error_cub("Allocation", env);
	if (!(env->game->sprite = create_sprite_tab(env->win.mlx,
	env->data.s_map, env->data.nbsprite)))
		error_cub("Allocation", env);
	if (env->data.resx == 1440 && env->data.resy == 900)
		init_bonus(env);
}

void	init_parse_struct(t_parse *data)
{
	data->floor.xpm = NULL;
	data->ceiling.xpm = NULL;
	data->floor.color = -1;
	data->ceiling.color = -1;
}

void	init_parse(t_global *env, int ac, char **av)
{
	int	fd;

	check_options(ac, av, env);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		perror(av[1]);
		error_cub("Memory", env);
	}
	ft_bzero(&env->data, sizeof(t_parse));
	init_parse_struct(&env->data);
	if (cub_parse(fd, &env->data) == 1)
		error_cub("Parse", env);
	if (check_parse(&env->data, &env->op) == 1)
		error_cub("Parse", env);
	if (check_validmap(&env->data) == 1)
		error_cub("Parse", env);
	if (close(fd) == -1)
	{
		perror(av[1]);
		error_cub("Memory", env);
	}
}
