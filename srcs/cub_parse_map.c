/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:53:17 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 11:02:09 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_around(t_parse data, int x, int y)
{
	if (y > 0)
	{
		if (data.map[y - 1][x] == ' ' || data.map[y - 1][x] == '\0')
			return(return_message_int("Map need to be circled by 1.", NULL, 1));
	}
	if (y < data.ymap - 1)
	{
		if (data.map[y + 1][x] == ' ' || data.map[y + 1][x] == '\0')
			return(return_message_int("Map need to be circled by 1.", NULL, 1));
	}
	if (x > 0)
	{
		if (data.map[y][x - 1] == ' ' || data.map[y][x - 1] == '\0')
			return(return_message_int("Map need to be circled by 1.", NULL, 1));
	}
	if (x < data.xmap - 1)
	{
		if (data.map[y][x + 1] == ' ' || data.map[y][x + 1] == '\0')
			return(return_message_int("Map need to be circled by 1.", NULL, 1));
	}
	return (0);
}

int		check_player(t_parse *data, int x, int y)
{
	if (check_around(*data, x, y))
		return (1);
	if (data->orientation > 68)
		return(return_message_int("2 Player detected.", NULL, 1));
	data->orientation = data->map[y][x];
	data->player.x = y + 0.5f;
	data->player.y = x + 0.5f;
	return (0);
}

int	check_pos_sprite(t_parse *data, int x, int y, t_list **s_map)
{
	t_list	*spritetmp;
	int			i;
	t_spritem *temp;

	temp = NULL;
	i = find_sprite_info(data->map[y][x], data);
	if (*s_map == NULL)
	{
		if (!(temp = malloc_smap(x, y, data->s_info[i])) || !(*s_map = ft_lstnew(temp)))
		{
			free(temp);
			return(return_message_int("Allocation Error", NULL, 1));
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

int		valid_sprite_player(t_parse *data, int x, int y, t_list **s_map)
{
	if (y == (data->ymap - 1) || x == (data->xmap - 1) || x == 0 || y == 0)
		if (data->map[y][x] != '1' && data->map[y][x] != ' ')
			return(return_message_int("Map need to be circled by 1.", NULL, 1));
	if (data->map[y][x] == '1')
		;
	else if (data->map[y][x] == '0'
	|| ft_chrcmp(data->symbol, data->map[y][x]) == 0)
	{
		if (ft_chrcmp(data->symbol, data->map[y][x]) == 0)
			check_pos_sprite(data, x, y, s_map);
		if (check_around(*data, x, y))
			return (1);
	}
	else if (data->map[y][x] == ' ')
		;
	else if (ft_chrcmp("WNES", data->map[y][x]) == 0)
	{
		if (check_player(data, x, y))
			return (1);
	}
	else
		return(return_message_int_c("Invalid character in Map: ",
		data->map[y][x], 1));
	return (0);
}

int		check_validmap(t_parse *data)
{
	int			x;
	int			y;
	int			err;
	t_smap_lst	*s_map;

	s_map = NULL;
	err = 0;
	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
		{
			if (err != 1)
				err = valid_sprite_player(data, x, y, &s_map);
			x++;
		}
		x = 0;
		y++;
	}
	fill_sprite(data, &s_map);
	ft_lstclear(&s_map, &free);
	return (err);
}