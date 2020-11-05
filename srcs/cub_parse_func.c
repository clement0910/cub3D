/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:52:05 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 15:00:05 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		parse_resolution(char *line, int *x, int *y)
{
	int		i;
	i = 1;
	if (*x != -1 && *y != -1)
		return(return_message_int("You cannot have multiples resolution.",
		NULL, 1));
	*x = ft_atoi_parse(line, &i);
	*y = ft_atoi_parse(line, &i);
	if (line[i] != '\0' || *x < 0 || *y < 0)
		return(return_message_int("Invalid resolution.", NULL, 1));
	return (0);
}

int		parse_textures(char *line, char **textures, const char *dir)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (*textures)
		return(return_message_int((char*)dir,
		" texture can't have more than one path.", 1));
	while (((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
			&& line[x] != '\0')
		x++;
	if (line[x] == '.' && line[x + 1] == '/')
	{
		y = x;
		while ((line[y] <= 9 || line[y] >= 13) && line[y] != '\0')
			y++;
		if (!(*textures = ft_substr(line, x, y - x)))
			return(return_message_int(
			"Allocation Problem in: ", (char*)dir, 1));
	}
	else
		return(return_message_int("No path find for ", (char*)dir, 1));
	return (0);
}


int		parse_color_rgb(char *line, t_colorxpm *color, const char *details)
{
	int		x;
	int		r;
	int		g;
	int		b;

	x = 0;
	r = ft_atoi_parse(line, &x);
	if (line[x] != ',')
		return (return_message_int((char*)details, " invalid.", 1));
	x++;
	g = ft_atoi_parse(line, &x);
	if (line[x] != ',')
		return (return_message_int((char*)details, " invalid.", 1));
	x++;
	b = ft_atoi_parse(line, &x);
	if (line[x] != '\0')
		return (return_message_int((char*)details, " invalid.", 1));
	if (r > 255 || b > 255 || g > 255 || r < 0 || g < 0 || b < 0)
		return (return_message_int("Wrong color parameters for ",
		(char*)details, 1));
	color->color = (0 << 24 | r << 16 | g << 8 | b);
	return (0);	
}

int		parse_xpmcolor(char *line, t_colorxpm *color, const char *details)
{
	int		x;

	x = 1;
	if (color->color > -1 || color->xpm)
		return(return_message_int((char*)details,
		" cannot have several path and color.", 1));	
	while (((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
			&& line[x] != '\0')
		x++;
	if (ft_isdigit(line[x]))
		return (parse_color_rgb(line + x, color, details));
	else if (line[x] == '.' && line[x + 1] == '/')
		return (parse_textures(line + x, &color->xpm, details));
	else
		return (return_message_int((char*)details, " info not found.", 1));
	return (0);
}