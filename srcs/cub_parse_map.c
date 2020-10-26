/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:53:17 by csapt             #+#    #+#             */
/*   Updated: 2020/10/24 18:46:07 by csapt            ###   ########lyon.fr   */
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

int		check_validmap(t_parse *data)
{
	int		x;
	int		y;
	int		xma;
	int		yma;
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
					return (1);
			if (data->map[y][x] == '1')
			{

			}
			else if (data->map[y][x] == '0' || data->map[y][x] == '2')
			{
				if (check_around(*data, x, y))
				{
					return (1);
				}
			}
			else if (data->map[y][x] == ' ')
			{
				
			}
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'O' || data->map
			[y][x] == 'W' || data->map[y][x] == 'S')
			{
				if (check_around(*data, x, y))
					return (1);
				if (data->orientation > 78)
					return (1);
				data->orientation = data->map[y][x];
				data->player.x = x;
				data->player.y = y;
			}
			else
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}