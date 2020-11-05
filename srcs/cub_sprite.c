/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:09:26 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 14:26:52 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_sprite		*create_sprite(void *mlx, t_spritei s_info, double x, double y)
{
	t_sprite	*sprite;

	if (!(sprite = malloc(sizeof(t_sprite))))
		return (NULL);
	if (!(sprite->sprite = create_tab_xpm(mlx, s_info.nsprite,
		s_info.xpm_sprite)))
	{
		free(sprite);
		return (NULL);
	}
	sprite->x = x;
	sprite->y = y;
	sprite->nsprite = s_info.nsprite;
	sprite->xpm = 0;
	return (sprite);
}

t_sprite		**create_sprite_tab(void *mlx, t_spritem *s_map, int size)
{
	int			x;
	t_sprite	**sprite;

	x = 0;
	if (!s_map)
		return (return_message("Invalid S_MAP", NULL));
	if (!(sprite = malloc((size + 1) * sizeof(t_sprite*))))
		return (NULL);
	while (x < size)
	{
		if (!(sprite[x] = create_sprite(mlx, s_map[x].s_info,
		s_map[x].x, s_map[x].y)))
		{
			free_sprite_tab(sprite, mlx, x + 1);
			return (NULL);
		}
		x++;
	}
	sprite[size] = NULL;
	return (sprite);
}

void		free_sprite(t_sprite *sprite, void *mlx)
{
	if (sprite)
	{
		if (sprite->sprite)
			free_image_tab(sprite->nsprite, sprite->sprite, mlx);
		free(sprite);
	}
}

void		free_sprite_tab(t_sprite **sprite, void *mlx, int size)
{
	int		x;

	x = 0;
	if (!sprite)
		return ;
	while (x < size)
	{
		free_sprite(sprite[x], mlx);
		x++;
	}
	free(sprite);
}
