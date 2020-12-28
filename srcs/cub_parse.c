/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:42:00 by csapt             #+#    #+#             */
/*   Updated: 2020/12/28 16:46:29 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_line(char *line, t_parse *data)
{
	int		x;

	x = 0;
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
		x++;
	if (line[x] == 'R')
		return (parse_resolution(line + x, &data->resx, &data->resy));
	else if (line[x] == 'N' && line[x + 1] == 'O')
		return (parse_textures(line + (x + 2), &data->xpm[NO], "NORTH"));
	else if (line[x] == 'S' && line[x + 1] == 'O')
		return (parse_textures(line + (x + 2), &data->xpm[SO], "SOUTH"));
	else if (line[x] == 'W' && line[x + 1] == 'E')
		return (parse_textures(line + (x + 2), &data->xpm[WE], "WEST"));
	else if (line[x] == 'E' && line[x + 1] == 'A')
		return (parse_textures(line + (x + 2), &data->xpm[EA], "EAST"));
	else if (line[x] == 'C')
		return (parse_xpmcolor(line + x, &data->ceiling, "CEILING"));
	else if (line[x] == 'F')
		return (parse_xpmcolor(line + x, &data->floor, "FLOOR"));
	else if (line[x] == '\0')
		return (0);
	return (1);
}

int		cub_parse_error(char *line, t_sinfo_lst **s_info, t_list **maplist,
						int *error)
{
	if (*error == 1 || *error == 3)
		*error = check_spritesinfo(line, s_info);
	if (*error == 1 || *error == 2)
		*error = check_map(line, maplist);
	if (*error == 1 || *error == 4)
	{
		free(line);
		ft_lstclear(maplist, &free);
		free_lst_sinfo(s_info);
		ft_lstclear(s_info, &free);
		return (1);
	}
	return (0);
}

int		cub_parse_clear(t_parse *data, t_list **maplist, t_sinfo_lst **s_info)
{
	if (fill_map(data, maplist) || fill_spriteinfo(data, s_info)
	|| fill_symbol(data))
	{
		ft_lstclear(maplist, &free);
		free_lst_sinfo(s_info);
		ft_lstclear(s_info, &free);
		return (1);
	}
	//ft_printdata(*data, maplist, s_info);
	ft_lstclear(maplist, &free);
	free_lst_sinfo(s_info);
	ft_lstclear(s_info, &free);
	return (0);
}

int		check_validmap(t_parse *data)
{
	int				x;
	int				y;
	int				err;
	t_smap_lst		*s_map;

	s_map = NULL;
	err = 0;
	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
		{
			if (err != 1)
				err = check_details_map(data, x, y, &s_map);
			x++;
		}
		x = 0;
		y++;
	}
	fill_sprite(data, &s_map);
	ft_lstclear(&s_map, &free);
	if (err == 0 && data->orientation == 0)
		return (return_message_i("Player not found.", NULL, 1));
	return (err);
}

int		cub_parse(int fd, t_parse *data)
{
	int				error;
	int				read;
	char			*line;
	t_list			*maplist;
	t_sinfo_lst		*s_info;

	error = 0;
	read = 1;
	maplist = NULL;
	s_info = NULL;
	while (read != 0)
	{
		read = get_next_line(fd, &line);
		if (error != 2)
			error = check_line(line, data);
		if (cub_parse_error(line, &s_info, &maplist, &error))
			return (1);
		free(line);
	}
	return (cub_parse_clear(data, &maplist, &s_info));
}
