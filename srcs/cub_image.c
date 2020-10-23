/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:03:29 by csapt             #+#    #+#             */
/*   Updated: 2020/10/23 17:29:51 by csapt            ###   ########lyon.fr   */
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
	image->line_length_i = image->line_length / 4;
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
		return (return_message("Invalid XPM File: ", tex_file));
	}
	xpm->addr = (int*)mlx_get_data_addr(xpm->img, &xpm->bits_per_pixel,
	&xpm->line_length, &xpm->endian);
	xpm->line_length_i = xpm->line_length / 4;
	return (xpm);
}

t_img		**create_tab_xpm(void *mlx, int size, char **xpm)
{
	int		x;
	t_img	**tab;

	x = 0;
	if (!xpm || ft_tablen(xpm) > size)
		return (return_message("Invalid XPM Tab", NULL));
	if (!(tab = malloc((size + 1) * sizeof(t_img*))))
		return (NULL);
	while (x < size)
	{
		if (!(tab[x] = create_xpm_image(mlx, xpm[x])))
		{
			free_image_tab(x + 1, tab, mlx);
			return (NULL);
		}
		x++;
	}
	tab[size] = NULL;
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

void		free_image_tab(int n, t_img **tab, void *mlx)
{
	int		x;

	x = 0;
	if (!tab)
		return ;
	while (x < n)
	{
		free_image(tab[x], mlx);
		x++;
	}
	free(tab);
}
