/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 00:03:03 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 20:24:55 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			print_lst_sprite(t_sinfo_lst **list)
{
	int			x;
	t_sinfo_lst *temp;

	temp = *list;
	x = 1;
	ft_printf("Number of sprites in chained lists: %d\n", ft_lstsize(temp));
	ft_printf("----------------------------------\n");
	while (temp)
	{
		ft_printf("Sprite %d:\n", x);
		print_lst(&((t_sprite_desc*)temp->content)->textures);
		ft_printf("-\n");
		temp = temp->next;
		x++;
	}
}

void			print_spritei(t_spritei s_info)
{
	ft_printf("----------------------------------\n");
	ft_printf("Number of XPM files: %d\n", s_info.nsprite);
	ft_printf("-\n");
	ft_printf("XPM files:\n");
	print_tab(s_info.xpm_sprite);
	ft_printf("-\n");
	ft_printf("Symbol of sprite: '%c'\n", s_info.c);
}

void			printdata(t_parse *data, t_list **maplist, t_sinfo_lst **sprite)
{
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("\nDATA OF PARSING WILL BE DISPLAYED\n\n");
	ft_putstr_fd(RESET_ERROR, 1);
	ft_printf("----------------------------------\n");
	ft_printf("Window resolution: x: %d | y: %d\n", data->resx, data->resy);
	ft_printf("North Texture: %s\n", data->xpm[NO]);
	ft_printf("South Texture: %s\n", data->xpm[SO]);
	ft_printf("East Texture: %s\n", data->xpm[EA]);
	ft_printf("West Texture: %s\n", data->xpm[WE]);
	if (data->ceiling.color == -1)
		ft_printf("Ceiling Texture: %s\n", data->ceiling.xpm);
	else
		ft_printf("Ceiling Color: %d\n", data->ceiling.color);
	if (data->floor.color == -1)
		ft_printf("Floor Texture: %s\n", data->floor.xpm);
	else
		ft_printf("Floor Texture: %d\n", data->floor.color);
	ft_printf("----------------------------------\n");
	printdata_map(data, maplist);
	printdata_sprite(data, sprite);
	ft_printf("----------------------------------\n");
}

void			printdata_map(t_parse *data, t_list **maplist)
{
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("MAP\n\n");
	ft_putstr_fd(RESET_ERROR, 1);
	ft_printf("Chained lists of map parsing:\n");
	ft_printf("----------------------------------\n");
	print_lst(maplist);
	ft_printf("-\n");
	ft_printf("Tab of map parsing:\n");
	ft_printf("----------------------------------\n");
	print_tab(data->map);
	ft_printf("-\n");
	ft_printf("Map Size: x: %d | y: %d\n", data->xmap, data->ymap);
	ft_printf("----------------------------------\n");
}

void			printdata_sprite(t_parse *data, t_sinfo_lst **sprite)
{
	int			x;

	x = 0;
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("SPRITE\n\n");
	ft_putstr_fd(RESET_ERROR, 1);
	print_lst_sprite(sprite);
	ft_printf("Number of sprites in tab: %d\n", data->nbspritei);
	while (x < data->nbspritei)
	{
		print_spritei(data->s_info[x]);
		x++;
	}
}
