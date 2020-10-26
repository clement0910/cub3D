/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 00:03:03 by csapt             #+#    #+#             */
/*   Updated: 2020/10/26 17:02:13 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_lst_sprite(t_sprite_list **list)
{
	t_sprite_list *temp;

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

void	print_spritei(t_spritei info)
{
	printf("sprite: %d\n", info.nsprite);
	print_tab(info.xpm_sprite);
}
void	ft_printdata(t_parse data, t_list **maplist, t_sprite_list **sprite)
{
	int		x;

	x = 0;
	printf("--------------------------------------\n");
	printf("X: %d | Y: %d\n", data.resx, data.resy);
	printf("north: %s\n", data.xpm[NO]);
	printf("south: %s\n", data.xpm[SO]);
	printf("east: %s\n", data.xpm[EA]);
	printf("west: %s\n", data.xpm[WE]);
	printf("sprite: %s\n", data.sprite);
	printf("ceiling: %d\n", data.ceiling.color);
	printf("floor: %d\n", data.floor.color);
	printf("---------------------------------------\n");
	print_lst(maplist);
	printf("---------------------------------------\n");
	print_tab(data.map);
	printf("---------------------------------------\n");
	printf("XMAP: %d | YMAP: %d\n", data.xmap, data.ymap);
	printf("---------------------------------------\n");
	print_lst_sprite(sprite);
	printf("---------------------------------------\n");
	printf("nbsprite: %d\n", data.nbsprite);
	while (x < data.nbsprite)
	{
		print_spritei(data.info[x]);
		printf("-------------\n");
		x++;
	}
}
