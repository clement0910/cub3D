/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:52:05 by csapt             #+#    #+#             */
/*   Updated: 2020/10/28 16:02:04 by csapt            ###   ########lyon.fr   */
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
	if (*x < 100 || *y < 100)
	{
		print_error("Resolution Too Low | Set to 100x100", true);
		*x = 100;
		*y = 100;
		return (0);
	}
	mlx_get_screen_size(mlx, &maxx, &maxy);
	if (*x > maxx || *y > maxy)
	{
		print_error("Resolution Too High | Set to ur screen size", true);
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
		while ((line[y] <= 9 || line[y] >= 13) && line[y] != '\0')
			y++;
		if (!(*textures = ft_substr(line, x, y - x)))
		{
			//error here
			return (1);
		}
	}
	else
	{
		return_message("No path find for ", (char*)dir);
		return (1);
	}
	return (0);
}

int		parse_xpmcolor(char *line, t_colorxpm *color, const char *details)
{
	int		x;
	int		r;
	int		g;
	int		b;

	x = 1;
	while (((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
			&& line[x] != '\0')
		x++;
	if (line[x] == '\0')
		return(return_message_int((char*)details, " not found.", 1));
	if (line[x] == '.' && line[x + 1] == '/')
		return (parse_textures(line, &color->xpm, details));
	r = ft_atoi_index(line, &x);
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32 || line[x] == ',')
		x++;
	if (line[x] == '\0')
		return(return_message_int((char*)details, " invalid.", 1));
	g = ft_atoi_index(line, &x);
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32 || line[x] == ',')
		x++;
	if (line[x] == '\0')
		return(return_message_int((char*)details, " invalid.", 1));
	b = ft_atoi_index(line, &x);
	if (r > 255 || b > 255 || g > 255)
	{
		return_message("Wrong color parameters for ", (char*)details);
		return (1);
	}
	color->color = (0 << 24 | r << 16 | g << 8 | b);
	return (0);
}
