/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:52:05 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:08:25 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		parse_resolution(char *line, void *mlx, int *x, int *y)
{
	int		i;
	int		maxx;
	int		maxy;

	i = 1;
	*x = ft_atoi_index(line, &i);
	*y = ft_atoi_index(line, &i);
	if (*x == 0 || *y == 0) //Minimum / Check for neg resolution
	{
		ft_putendl_fd("Wrong resolution, bad characters or resolution too low !"
		, 1);
		ft_putendl_fd("Minimum is ... / Check your .cub", 1);
		return (1); //Error
	}
	mlx_get_screen_size(mlx, &maxx, &maxy);
	if (*x > maxx || *y > maxy)
	{
		printf("\033[31;1;4mWARNING ! / Resolution too high !\033[0m\n");
		printf("Set to %d x %d\n", maxx, maxy);
		*x = maxx;
		*y = maxy;
		return (0);
	}
	return (0);
}

int		parse_textures(char *line, char **textures, const char *dir)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (line[x] != '.' && line[x] != '\0')
		x++;
	if (line[x] == '.' && line[x + 1] == '/')
	{
		y = x;
		while ((line[y] <= 9 || line[y] >= 13) && line[y] != 32 && line[y] !=
		'\0')
			y++;
		*textures = ft_substr(line, x, y - x);
	}
	else
	{
		write(1, "NO PATH FIND FOR ", 18);
		ft_putendl_fd((char*)dir, 1);
		ft_putendl_fd("Make sure you use './'", 1);
		//FREE
		return (1);
	}
	return (0);
}

int		parse_xpmcolor(char *line, int *color, const char *details)
{
	int		x;
	int		r;
	int		g;
	int		b;

	x = 1;
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
		x++;
	r = ft_atoi_index(line, &x);
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32 || line[x] == ',')
		x++;
	g = ft_atoi_index(line, &x);
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32 || line[x] == ',')
		x++;
	b = ft_atoi_index(line, &x);
	if (r > 255 || b > 255 || g > 255)
	{
		write(1, "Wrong color parameters for ", 27);
		ft_putendl_fd((char*)details, 1);
		return (1);
	}
	*color = (0 << 24 | r << 16 | g << 8 | b);
	return (0);
}
