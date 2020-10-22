/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:42:00 by csapt             #+#    #+#             */
/*   Updated: 2020/10/22 14:51:28 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			check_map(char *line, t_list **maplist)
{
	int			x;

	x = 0;
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
		x++;
	if (line[x] == '0')
	{
		return_message("Invalid Map in line: ", line);
		return (1);
	}
	else if (line[x] == '1')
	{
		if (*maplist == NULL)
			*maplist = ft_lstnew(ft_strdup(line));
		else
			ft_lstadd_back(maplist, ft_lstnew(ft_strdup(line)));
		return (2);
	}
	else
		return (1);
}

int			check_line(char *line, void *mlx, t_parse *data)
{
	int		x;

	x = 0;
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
		x++;
	if (line[x] == 'R')
		return (parse_resolution(line + x, mlx, &data->resx, &data->resy));
	else if (line[x] == 'N' && line[x + 1] == 'O')
		return (parse_textures(line + x, &data->xpm[NO], "NORTH"));
	else if (line[x] == 'S' && line[x + 1] == 'O')
		return (parse_textures(line + x, &data->xpm[SO], "SOUTH"));
	else if (line[x] == 'W' && line[x + 1] == 'E')
		return (parse_textures(line + x, &data->xpm[WE], "WEST"));
	else if (line[x] == 'E' && line[x + 1] == 'A')
		return (parse_textures(line + x, &data->xpm[EA], "EAST"));
	else if (line[x] == 'S')
		return (parse_textures(line + x, &data->sprite, "SPRITE"));
	else if (line[x] == 'C')
		return (parse_xpmcolor(line + x, &data->ceiling.color, "CEILING"));
	else if (line[x] == 'F')
		return (parse_xpmcolor(line + x, &data->floor.color, "FLOOR"));
	else if (line[x] == '\0')
		return (0);
	return (1);
}

int			cub_parse(int fd, t_parse *data, void *mlx)
{
	int		error;
	int		read; 
	char	*line;
	t_list	*maplist;

	error = 0;
	read = 1;
	maplist = NULL;
	while (read != 0)
	{
		read = get_next_line(fd, &line);
		if (error != 2)
			error = check_line(line, mlx, data);
		if (error == 1 || error == 2)
			error = check_map(line, &maplist);
		if (error == 1)
		{
			free(line);
			ft_lstclear(&maplist, &free);
			return (1);
		}
		free(line);
	}
	filling_tab(data, &maplist);
	ft_lstclear(&maplist, &free);
	return (0);
}
