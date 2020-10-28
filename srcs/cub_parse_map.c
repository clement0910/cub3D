/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:53:17 by csapt             #+#    #+#             */
/*   Updated: 2020/10/28 14:34:48 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_around(t_parse data, int x, int y)
{
	if (y > 0)
	{
		if (data.map[y - 1][x] == ' ' || data.map[y - 1][x] == '\0')
			return (1);
	}
	if (y < data.ymap - 1)
	{
		if (data.map[y + 1][x] == ' ' || data.map[y + 1][x] == '\0')
			return (1);
	}
	if (x > 0)
	{
		if (data.map[y][x - 1] == ' ' || data.map[y][x - 1] == '\0')
			return (1);
	}
	if (x < data.xmap - 1)
	{
		if (data.map[y][x + 1] == ' ' || data.map[y][x + 1] == '\0')
			return (1);
	}
	return (0);
}

int		check_player(t_parse *data, int x, int y)
{
	if (check_around(*data, x, y))
		return (1);
	if (data->orientation > 78)
		return (1);
	data->orientation = data->map[y][x];
	data->player.x = x;
	data->player.y = y;
	return (0);
}

int	check_pos_sprite(t_parse *data, char c, int x, int y, t_list **s_map)
{
	t_list	*spritetmp;
	int			i;
	t_spritem *temp;

	temp = NULL;
	i = 0;
	while (i < data->nbspritei)
	{
		if (data->s_info[i].c == c)
			break;
		i++;
	}
	if (*s_map == NULL)
	{
		if (!(temp = malloc_smap(x, y, data->s_info[i])) || !(*s_map = ft_lstnew(temp)))
		{
			free(temp);
			return_message_int("Allocation Error", NULL, 1);
		}
	}
	else
	{
		if (!(temp = malloc_smap(x, y, data->s_info[i])) || !(spritetmp = ft_lstnew(temp)))
		{
			free(temp);
			return(return_message_int("Allocation Error", NULL, 1));		
		}
		ft_lstadd_back(s_map, spritetmp);
	}
	return (0);
}


int		check_validmap(t_parse *data)
{
	int			x;
	int			y;
	int			xma;
	int			yma;
	t_smap_lst	*s_map;

	s_map = NULL;
	x = 0;
	y = 0;
	xma = data->xmap - 1;
	yma = data->ymap - 1;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
		{
			if (y == yma || x == xma || x == 0 || y == 0)
				if (data->map[y][x] != '1' && data->map[y][x] != ' ')
				{
					ft_lstclear(&s_map, &free);
					return (1);
				}
			if (data->map[y][x] == '1')
				;
			else if (data->map[y][x] == '0' || ft_chrcmp(data->symbol, data->map[y][x]) == 0)
			{
				if (ft_chrcmp(data->symbol, data->map[y][x]) == 0)
					check_pos_sprite(data, data->map[y][x], y, x, &s_map);	
				if (check_around(*data, x, y))
				{
					ft_lstclear(&s_map, &free);
					return (1);
				}
			}
			else if (data->map[y][x] == ' ')
				;
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'O' ||
			data->map[y][x] == 'W' || data->map[y][x] == 'S')
			{
				if (check_player(data, x, y))
				{
					ft_lstclear(&s_map, &free);
					return (1);
				}
			}
			else
			{
				ft_lstclear(&s_map, &free);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	//if s_map == NULL
	fill_sprite(data, &s_map);
	//print_lstmap(&s_map, data);
	//fill_sprite(data, &s_map);
	ft_lstclear(&s_map, &free);
	if (data->orientation == 0)
		return(return_message_int("Player not found.", NULL, 1));
	return (0);
}