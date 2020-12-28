/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:14:17 by csapt             #+#    #+#             */
/*   Updated: 2020/12/28 10:16:59 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		calcul_mapsize(t_parse *data, t_vec2i *mapwrite, int *ratio)
{
	int		nom;
	int		maxmapxy;
	t_vec2i maxmap;
	t_vec2i	mapsize;

	maxmap.x = data->resx * 0.8;
	maxmap.y = data->resy * 0.8;
	maxmapxy = (data->xmap > data->ymap) ? data->xmap : data->ymap;
	nom = (maxmap.x < maxmap.y) ? maxmap.x : maxmap.y;
	*ratio = (nom / maxmapxy);
	mapsize.x = *ratio * data->xmap;
	mapsize.y = *ratio * data->ymap;
	mapwrite->x = (data->resx - mapsize.x) / 2;
	mapwrite->y = (data->resy - mapsize.y) / 2;
}

void		print_map(t_parse *data, t_img *img, int ratio, t_vec2i mapwrite)
{
	t_vec2i coord;
	int		xtmp;

	coord.x = 0;
	coord.y = 0;
	while (data->map[coord.y] != NULL)
	{
		xtmp = mapwrite.x;
		while (data->map[coord.y][coord.x])
		{
			if (data->map[coord.y][coord.x] == '1')
				print_square(img, BLACK, mapwrite, ratio);
			else if (data->map[coord.y][coord.x] == '0' ||
			ft_chrcmp("WNES", data->map[coord.y][coord.x]) == 0)
				print_square(img, WHITE, mapwrite, ratio);
			else if (data->map[coord.y][coord.x] == ' ')
				;
			else
				print_square(img, MAGENTA, mapwrite, ratio);
			mapwrite.x = mapwrite.x + ratio;
			coord.x++;
		}
		calcul_print_map(&mapwrite, &coord, xtmp, ratio);
	}
}

void		calcul_print_map(t_vec2i *mapw, t_vec2i *coord, int xtmp, int ratio)
{
	mapw->x = xtmp;
	coord->x = 0;
	mapw->y = mapw->y + ratio;
	coord->y++;
}

void		print_player(t_parse *data, t_img *img, int ratio, t_vec2i mapwrite)
{
	mapwrite.x = (mapwrite.x + (ratio * (int)data->player.y));
	mapwrite.y = (mapwrite.y + (ratio * (int)data->player.x));
	print_square(img, BLUE, mapwrite, ratio);
}

void		main_map(t_parse *data, t_img *img, t_raycast *rc)
{
	int		ratio;
	t_vec2i	mapwrite;

	if (data->resx < 500 || data->resy < 500)
		return ;
	calcul_mapsize(data, &mapwrite, &ratio);
	print_map(data, img, ratio, mapwrite);
	print_player(data, img, ratio, mapwrite);
	mapwrite.x = (mapwrite.x + (ratio * (int)data->player.y));
	mapwrite.y = (mapwrite.y + (ratio * (int)data->player.x));
	print_line((t_vec2i){mapwrite.x + ratio / 2, mapwrite.y + ratio / 2},
	(t_vec2i){mapwrite.x + (rc->dir.y * ratio) + ratio / 2, mapwrite.y +
	(rc->dir.x * ratio) + ratio / 2}, img);
}
