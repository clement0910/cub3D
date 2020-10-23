/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:09:26 by csapt             #+#    #+#             */
/*   Updated: 2020/10/23 16:21:41 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_sprite *create_sprite(void *mlx, t_spritei spritei)
{
	t_sprite 	*sprite;

	if (!(sprite = malloc(sizeof(t_sprite))))
		return (NULL);
	if (!(sprite->sprite = create_tab_xpm(mlx, spritei.nsprite,
		spritei.xpm_sprite)))
		return (NULL);
	sprite->x = spritei.x;
	sprite->y = spritei.y;
	sprite->nsprite = spritei.nsprite;
	sprite->xpm = 0;
	return (sprite);
}

t_sprite	**create_sprite_tab(void *mlx, t_spritei *spritei, int size)
{
	int			x;
	t_sprite	**sprite;

	x = 0;
	if (!spritei)
		return (return_message("Invalid Sprite Info", NULL));
	if (!(sprite = malloc((size + 1) * sizeof(t_sprite*))))
		return(NULL);
	while (x < size)
	{
		if (!(sprite[x] = create_sprite(mlx, spritei[x])))
		{
			free_sprite_tab(sprite, mlx, x + 1);
			return (NULL);
		}
		x++;
	}
	sprite[size] = NULL;
	return (sprite);
}

void	free_sprite(t_sprite *sprite, void *mlx)
{
	if (sprite)
	{
		if(sprite->sprite)
			free_image_tab(sprite->nsprite, sprite->sprite, mlx);
		free(sprite);
	}
}

void	free_sprite_tab(t_sprite **sprite, void *mlx, int size)
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