/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:14:17 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 23:50:37 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_block_map(t_img *img, int color, t_vec2i mapwrite,
						int ratio)
{
	int i;
	int z;
	int xtmp;

	i = 0;
	z = 0;
	while (i < ratio)
	{
		xtmp = mapwrite.x;
		while (z < ratio)
		{
			//? transparent
			write_pixel(img, mapwrite.x, mapwrite.y, color);
			z++;
			mapwrite.x++;
		}
		mapwrite.x = xtmp;
		z = 0;
		i++;
		mapwrite.y++;
	}
}

void	calcul_mapsize(t_parse *data, t_vec2i *mapwrite, int *ratio)
{
	t_vec2i	mapsize;
	t_vec2i maxmap;
	int		maxmapxy;
	int 	nom;

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
	int		x;
	int		y;
	int		xtmp;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		xtmp = mapwrite.x;
		while(data->map[y][x])
		{
			if (data->map[y][x] == '1')
				print_block_map(img, BLACK, mapwrite, ratio);
			else if (data->map[y][x] == '0' || ft_chrcmp("WNES", data->map[y][x]) == 0)
				print_block_map(img, WHITE, mapwrite, ratio);
			else if (data->map[y][x] == ' ')
				;
			else
				print_block_map(img, MAGENTA, mapwrite, ratio);
			mapwrite.x = mapwrite.x + ratio;
			x++;
		}
		mapwrite.x = xtmp;
		x = 0;
		mapwrite.y = mapwrite.y + ratio;
		y++;
	}
}

void		print_player(t_parse *data, t_img *img, int ratio, t_vec2i mapwrite)
{
	mapwrite.x = (mapwrite.x + (ratio * (int)data->player.y));
	mapwrite.y = (mapwrite.y + (ratio * (int)data->player.x));
	print_block_map(img, RED, mapwrite, ratio);
}

void		main_map(t_parse *data, t_img *img)
{
	int		ratio;
	t_vec2i	mapwrite;
	if (data->resx < 500 || data->resy < 500)
		return ;
	calcul_mapsize(data, &mapwrite, &ratio);
	print_map(data, img, ratio, mapwrite);
	print_player(data, img, ratio, mapwrite);
}