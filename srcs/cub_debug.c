/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 00:03:03 by csapt             #+#    #+#             */
/*   Updated: 2020/10/28 19:14:43 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_lst_sprite(t_sinfo_lst **list)
{
	t_sinfo_lst *temp;

	temp = *list;
	printf("%d\n", ft_lstsize(temp));
	while (temp)
	{
		print_lst(&((t_sprite_desc*)temp->content)->textures);
		printf("---------\n");
		temp = temp->next;
	}
}

void	print_lst(t_list **maplist)
{
	t_list *temp;

	temp = *maplist;
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
}

void	print_lstmap(t_list **spritelist, t_parse *data)
{
	t_list *temp;
	int		x;

	x = 0;
	temp = *spritelist;
	printf("size: %d\n", ft_lstsize(temp));
	while (temp)
	{
		printf("x:%f| y:%f\n", ((t_spritem*)temp->content)->x, ((t_spritem*)temp->content)->y);
		print_spritei(((t_spritem*)temp->content)->s_info);
		temp = temp->next;
	}
	printf("------------------\n");
	printf("size:%d\n", data->nbsprite);
	while (x < data->nbsprite)
	{
		printf("x: %f| y: %f\n", data->s_map[x].x, data->s_map[x].y);
		print_spritei(data->s_map[x].s_info);
		x++;
	}
}

void	print_tab(char **tab)
{
	int x;

	x = 0;
	while (tab[x] != NULL)
	{
		printf("%s\n", tab[x]);
		x++;
	}
}

void	print_spritei(t_spritei s_info)
{
	printf("sprite: %d\n", s_info.nsprite);
	printf("sign: %c\n", s_info.c);
	print_tab(s_info.xpm_sprite);
}

void	ft_printdata(t_parse data, t_list **maplist, t_sinfo_lst **sprite)
{
	int		x;

	x = 0;
	printf("--------------------------------------\n");
	printf("X: %d | Y: %d\n", data.resx, data.resy);
	printf("north: %s\n", data.xpm[NO]);
	printf("south: %s\n", data.xpm[SO]);
	printf("east: %s\n", data.xpm[EA]);
	printf("west: %s\n", data.xpm[WE]);
	printf("ceiling: %d\n", data.ceiling.color);
	printf("ceiling: %s\n", data.ceiling.xpm);
	printf("floor: %d\n", data.floor.color);
	printf("floor: %s\n", data.floor.xpm);
	printf("symbol: %s\n", data.symbol);
	printf("---------------------------------------\n");
	print_lst(maplist);
	printf("---------------------------------------\n");
	print_tab(data.map);
	printf("---------------------------------------\n");
	printf("XMAP: %d | YMAP: %d\n", data.xmap, data.ymap);
	printf("---------------------------------------\n");
	print_lst_sprite(sprite);
	printf("---------------------------------------\n");
	printf("nbspritei: %d\n", data.nbspritei);
	while (x < data.nbspritei)
	{
		print_spritei(data.s_info[x]);
		printf("-------------\n");
		x++;
	}
	printf("---------------------------------------\n");
}
