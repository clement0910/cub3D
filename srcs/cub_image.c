/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:03:29 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 17:54:58 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_img		*create_image(void *mlx, int x, int y)
{
	t_img	*image;

	if (!(image = malloc(sizeof(t_img))))
		return (NULL);
	if (!(image->img = mlx_new_image(mlx, x, y)))
	{
		free_image(image, mlx);
		return (NULL);
	}
	image->addr = (int*)mlx_get_data_addr(image->img, &image->bits_per_pixel,
	&image->line_length, &image->endian);
	image->width = x;
	image->height = y;
	image->line_lenght_i = image->line_length / 4;
	return (image);
}

t_img		*create_xpm_image(void *mlx, char *tex_file)
{
	t_img	*xpm;

	if (!(xpm = malloc(sizeof(t_img))))
		return (NULL);
	if (!(xpm->img = mlx_xpm_file_to_image(mlx, tex_file,
	&xpm->width, &xpm->height)))
	{
		free_image(xpm, mlx);
		return (NULL);
	}
	xpm->addr = (int*)mlx_get_data_addr(xpm->img, &xpm->bits_per_pixel,
	&xpm->line_length, &xpm->endian);
	xpm->line_lenght_i = xpm->line_lenght_i / 4;
	return (xpm);
}

t_img		**create_tab_xpm(void *mlx, int x, int y)
{
	t_img	**tab;

	if (!(tab = malloc(5 * sizeof(t_img*))))
		return (NULL);
	if (!(tab[0] = create_xpm_image(mlx, "assets/ui/menu/menu.xpm")))
	{
		//echec d'allouer fichier.xpm;
		return (NULL);
	}
	if (!(tab[1] = create_xpm_image(mlx, "assets/ui/menu/menu_p.xpm")))
	{
		//echec d'allouer fichier.xpm;
		return (NULL);
	}
	if (!(tab[2] = create_xpm_image(mlx, "assets/ui/menu/menu_s.xpm")))
	{
		//echec d'allouer fichier.xpm;
		return (NULL);
	}
	if (!(tab[3] = create_xpm_image(mlx, "assets/ui/menu/menu_q.xpm")))
	{
		//echec d'allouer fichier.xpm;
		return (NULL);
	}
	tab[4] = NULL;
	return (tab);
}

void		free_image(t_img *image, void *mlx)
{
	if (image)
	{
		if (image->img)
			mlx_destroy_image(mlx, image->img);
		free(image);
	}
}
