/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_spriteinfo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:00:54 by csapt             #+#    #+#             */
/*   Updated: 2020/10/28 14:00:50 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list			*malloc_texlist(char *line, int x, int y)
{
	t_list			*list;
	char			*temp;

	if (!(temp = ft_substr(line, x, y - x)))
		return (return_message("Cannot allocate memory", NULL));
	if (!(list = ft_lstnew(temp)))
	{
		free(temp);
		return (return_message("Cannot allocate memory", NULL));
	}
	return (list);
}

t_sprite_desc	*malloc_sdesc(char *line, int x, int y)
{
	t_sprite_desc	*desc;

	if (!(desc = ft_calloc(1, sizeof(t_sprite_desc))))
		return (return_message("Cannot allocate memory", NULL));
	if (!(desc->textures = malloc_texlist(line, x, y)))
	{
		free(desc);
		return (return_message("Cannot allocate memory", NULL));
	}
	if (line[y] != 9 || line[y + 1] == '\0') //Check symbol
	{
		ft_lstclear(&desc->textures, &free);
		free(desc);
		return (return_message("Cannot find symbol for sprite: ", line));
	}
	else
		desc->c = line[y + 1];
	return (desc);
}

int				new_spritesinfo(char *line, t_sinfo_lst **s_info)
{
	int				x;
	int				y;
	t_sprite_desc	*desc;

	x = 0;
	y = x;
	desc = NULL;
	while ((line[y] < 9 || line[y] >= 13) && line[y] != '\0')
		y++;
	if (*s_info == NULL)
	{
		if (!(desc = malloc_sdesc(line, x, y))
			|| !(*s_info = ft_lstnew(desc)))
		{
			free(desc);
			return (return_message_int("Allocation Error", NULL, 4));
		}
	}
	else
		return (addback_spritesinfo(line, s_info, x, y));
	return (3);
}

int				addback_spritesinfo(char *line, t_sinfo_lst **s_info,
				int x, int y)
{
	t_sprite_desc	*desc;
	t_sinfo_lst		*temp;

	desc = NULL;
	if (!(desc = malloc_sdesc(line, x, y))
		|| !(temp = ft_lstnew(desc)))
	{
		free(desc);
		return (return_message_int("Allocation Error", NULL, 4));
	}
	ft_lstadd_back(s_info, temp);
	return (3);
}

int				textures_of_sprites(char *line, t_sinfo_lst **s_info)
{
	int				x;
	int				y;
	t_sinfo_lst		*temp;

	x = 0;
	y = x;
	while ((line[y] <= 9 || line[y] >= 13) && line[y] != '\0')
		y++;
	if (!(temp = malloc_texlist(line, x, y)))
		return (return_message_int("Allocation Error", NULL, 4));
	ft_lstadd_back(&((t_sprite_desc*)ft_lstlast(*s_info)->content)->textures,
	temp);
	return (3);
}
