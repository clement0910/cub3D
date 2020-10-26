/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:41:11 by csapt             #+#    #+#             */
/*   Updated: 2020/10/26 17:01:50 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	filling_map(t_parse *data, t_list **maplist)
{
	int				x;
	t_list			*temp;

	x = 0;
	temp = *maplist;
	data->xmap = ft_lstmaxlen(maplist);
	data->map = malloc((ft_lstsize(temp) + 1) * sizeof(char*)); //proteger ce malloc calloc ?
	while (temp)
	{
		data->map[x] = ft_calloc(data->xmap + 1, sizeof(char));
		ft_strlcpy(data->map[x], (char*)temp->content, data->xmap + 1);
		temp = temp->next;
		x++;
	}
	data->map[x] = NULL;
	data->ymap = ft_tablen(data->map);
}

char	**filling_tab(t_list **list)
{
	char	**tab;
	int		x;
	int		length;
	t_list	*temp;

	x = 0;
	temp = *list;
	length = ft_lstsize(temp);
	if (!(tab = ft_calloc(length + 1, sizeof(char*))))
		return (NULL);
	while (temp)
	{
		if (!(tab[x] = ft_calloc(ft_strlen(temp->content) + 1, sizeof(char)))) //free ce qui a avant
			return (NULL);
		ft_strlcpy(tab[x], (char*)temp->content, ft_strlen(temp->content) + 1);
		temp = temp->next;
		x++;
	}
	tab[x] = NULL;
	return(tab);
}

void	filling_sprite(t_parse *data, t_sprite_list **slist)
{
	int				x;
	t_sprite_list	*temp;

	x = 0;
	temp = *slist;
	data->nbsprite = ft_lstsize(temp);
	data->info = malloc((data->nbsprite + 1) * sizeof(t_spritei));
	while(temp)
	{
		if (!(data->info[x].xpm_sprite = filling_tab(&((t_sprite_desc*)temp->content)->textures)))
		{
			return ;
		}
		data->info[x].nsprite = ft_tablen(data->info[x].xpm_sprite);
		data->info[x].c = ((t_sprite_desc*)temp->content)->c;
		temp = temp->next;
		x++;
	}
}