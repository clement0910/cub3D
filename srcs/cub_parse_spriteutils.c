/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_spriteutils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:19:10 by csapt             #+#    #+#             */
/*   Updated: 2020/10/29 00:46:25 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_spritem	*malloc_smap(double x, double y, t_spritei s_info)
{
	t_spritem	*s_map;

	if (!(s_map = ft_calloc(1, sizeof(t_spritem))))
		return (return_message("Cannot allocate memory", NULL));
	s_map->s_info = s_info;
	s_map->x = y + 0.5f;
	s_map->y = x + 0.5f;
	return (s_map);
}

int			find_sprite_info(char c, t_parse *data)
{
	int i;

	i = 0;
	while (i < data->nbspritei)
	{
		if (data->s_info[i].c == c)
			return(i);
		i++;
	}
	return (i);
}
void		free_lst_sinfo(t_sinfo_lst **s_info)
{
	t_list		*temp;

	temp = *s_info;
	while (temp)
	{
		ft_lstclear(&((t_sprite_desc*)temp->content)->textures, &free);
		temp = temp->next;
	}
}

void		free_spritei(t_spritei *s_info, int x)
{
	int			i;

	i = 0;
	while (x > i)
	{
		ft_free_tab(s_info[i].xpm_sprite);
		i++;
	}
	free(s_info);
}

int			check_spritesinfo(char *line, t_sinfo_lst **s_info)
{
	int			x;

	x = 0;
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
		x++;
	if (line[x] == 'S' && line[x + 1] == ' ')
	{
		while (line[x] != '.' && line[x] != '\0')
			x++;
		if (line[x] == '.' && line[x + 1] == '/')
			return (new_spritesinfo(line + x, s_info));
	}
	else if (line[x] == '-' && line[x + 1] == ' ')
	{
		while (line[x] != '.' && line[x] != '\0')
			x++;
		if (line[x] == '.' && line[x + 1] == '/')
			return (textures_of_sprites(line + x, s_info));
	}
	return (1);
}
