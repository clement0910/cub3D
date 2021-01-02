/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:43:36 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 16:58:01 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		start_bmp(t_global *env)
{
	ft_bzero(env->game->game->addr, env->data.resy *
	env->game->game->line_length);
	main_raycast(env->game, &env->data, env->op);
	main_sprite(env->game, &env->data);
	if (env->op.ceilflooron)
		main_floor(env->game, &env->data);
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->game->game->img
	, 0, 0);
	init_bmp(env);
	free_cub(env, 0);
	return (0);
}

void	fill_header(t_bmpfileheader *bfh, t_bmpinfoheader *bih, t_parse *data)
{
	bfh->signature[0] = 'B';
	bfh->signature[1] = 'M';
	bfh->bmp_size = data->resy * data->resx * 4 + 70;
	bfh->reserved1 = 0;
	bfh->reserved2 = 0;
	bfh->offset = 70;
	bih->header_size = 56;
	bih->width = data->resx;
	bih->height = data->resy;
	bih->planes = 1;
	bih->bit_pxl = 32;
	bih->compression = 3;
	bih->image_size = data->resy * data->resx * 4;
	bih->res_x = 0;
	bih->res_y = 0;
	bih->color_img = 0;
	bih->color_important = 0;
	bih->red_mask = 0x00FF0000;
	bih->green_mask = 0x0000FF00;
	bih->blue_mask = 0x000000FF;
	bih->alpha_mask = 0xFF000000;
}

int		*int_to_bmp(t_parse *data, t_img *img)
{
	int		*bmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(bmp = malloc(sizeof(int) * data->resx * data->resy)))
		return (NULL);
	while (y < data->resy)
	{
		x = 0;
		while (x < data->resx)
		{
			bmp[(data->resy - 1 - y) * data->resx + x] =
			img->addr[y * img->line_length_i + x] |
			0xFF000000;
			x++;
		}
		y++;
	}
	return (bmp);
}

void	init_bmp(t_global *env)
{
	int				fd;
	int				*bmp;
	t_bmpfileheader bfh;
	t_bmpinfoheader bih;

	fill_header(&bfh, &bih, &env->data);
	fd = open("save.bmp", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		error_cub("FD", env);
	if (write(fd, &bfh, 14) == -1)
		error_cub("Write", env);
	if (write(fd, &bih, bih.header_size) == -1)
		error_cub("Write", env);
	if (!(bmp = int_to_bmp(&env->data, env->game->game)))
		error_cub("Allocation", env);
	if (write(fd, bmp, bih.image_size) == -1)
		error_cub("Write", env);
	free(bmp);
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("Screenshot 📸\n");
	ft_putstr_fd(RESET_ERROR, 1);
	close(fd);
}
