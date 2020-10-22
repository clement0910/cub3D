/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 00:03:03 by csapt             #+#    #+#             */
/*   Updated: 2020/10/22 12:53:01 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	ft_printdata(t_parse data, t_list **maplist)
{
	t_list	*temp;
	int		x;

	x = 0;
	temp = *maplist;
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
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
	printf("---------------------------------------\n");
	print_tab(data.map);
	printf("---------------------------------------\n");
	printf("XMAP: %d | YMAP: %d\n", data.xmap, data.ymap);
	printf("---------------------------------------\n");
}
