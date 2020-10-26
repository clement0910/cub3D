/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:00:54 by csapt             #+#    #+#             */
/*   Updated: 2020/10/26 16:09:11 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list	*malloc_textures_list(char *line, int x, int y)
{
	t_list *list;
	char *temp;
	if (!(temp = ft_substr(line, x, y - x)))
		return (NULL);
	if (!(list = ft_lstnew(temp)))
	{
		free(temp);
		return (NULL);
	}
	return(list);
}

t_sprite_desc *malloc_sprite_desc(char *line, int x, int y)
{
	t_sprite_desc *desc;
				
	if (!(desc = ft_calloc(1, sizeof(t_sprite_desc))))
		return (NULL);
	if (!(desc->textures = malloc_textures_list(line, x, y)))
	{
		free(desc);
		return (NULL);
	}
	return(desc);
}

