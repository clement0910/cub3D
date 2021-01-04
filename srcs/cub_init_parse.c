/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:17:06 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 13:44:22 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_options(int ac, char **av, t_optis *op)
{
	if (ac > 3 || ac < 2)
		return (return_message_i("Use ./Cub3D --help for more info.", NULL, 1));
	if (ft_strncmp(av[1], "--help", 6) == 0)
		help_message(&op->help);
	else if (ft_strcmp(av[1], "--credits") == 0)
		credits_message(&op->help);
	if (!av[2])
		return (0);
	if (ft_strcmp(av[2], "--data") == 0)
		op->data = true;
	else if (ft_strcmp(av[2], "--save") == 0)
		op->save = true;
	else if (ft_strcmp(av[2], "--ignore") == 0)
		op->ignore = true;
	else
		return (return_message_i("Use ./Cub3D --help for more info.", NULL, 1));
	return (0);
}

int		check_filename(char *str)
{
	char	*file;

	if (ft_strlen((char*)str) <= 4)
	{
		ft_printf("Invalid file name, put .cub file.\n");
		return (1);
	}
	file = ft_strrchr((char*)str, '.');
	if (file == NULL)
		return (1);
	if (ft_strncmp(file, ".cub", 4) != 0 || file[4] != '\0')
	{
		ft_printf("Invalid file name, put .cub file.\n");
		return (1);
	}
	return (0);
}

void	init_parse_struct(t_parse *data)
{
	data->floor.xpm = NULL;
	data->ceiling.xpm = NULL;
	data->floor.color = -1;
	data->ceiling.color = -1;
	data->resx = -1;
	data->resy = -1;
}

void	start_parse(t_global *env, int fd, char **av)
{
	if (cub_parse(fd, &env->data, &env->op) || check_parse(&env->data, &env->op)
	|| check_validmap(&env->data))
	{
		if (close(fd) == -1)
		{
			perror(av[1]);
			error_cub("Memory", env);
		}
		error_cub("Parse", env);
	}
	if (close(fd) == -1)
	{
		perror(av[1]);
		error_cub("Memory", env);
	}
}

int		init_parse(t_global *env, int ac, char **av)
{
	int	fd;

	if (check_options(ac, av, &env->op))
		error_cub("Command", env);
	if (env->op.help)
		return (1);
	if (check_filename(av[1]))
		error_cub("Parse", env);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		perror(av[1]);
		error_cub("Memory", env);
	}
	ft_bzero(&env->data, sizeof(t_parse));
	init_parse_struct(&env->data);
	start_parse(env, fd, av);
	return (0);
}
