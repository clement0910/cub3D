/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:31:25 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 22:18:31 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_parse(t_parse *data, t_optis *op)
{
	if (data->resx < 0 || data->resy < 0)
		return (return_message_i("Resolution not found.", NULL, 1));
	if (data->floor.xpm == NULL && data->floor.color == -1)
	{
		return (return_message_i(
		"Floor not found | Fill in a with texture or int.", NULL, 1));
	}
	if (data->ceiling.xpm == NULL && data->ceiling.color == -1)
	{
		return (return_message_i(
		"Ceiling not found | Fill in with a texture or int.", NULL, 1));
	}
	if (check_textures(data))
		return (1);
	if (data->map == NULL)
		return (return_message_i("Map not found.", NULL, 1));
	if (data->nbspritei == 0)
	{
		return (return_message_i(
		"Sprite not found | 1 is mandatory.", NULL, 1));
	}
	check_ceilingandfloor(data, op);
	return (0);
}

void	check_ceilingandfloor(t_parse *data, t_optis *op)
{
	if (data->floor.xpm && data->ceiling.xpm)
		op->ceilflooron = true;
	if (data->floor.xpm && data->ceiling.xpm == NULL)
	{
		if (!op->ignore)
			print_error(
			"Need ceiling texture to display the floor and ceiling.", true);
	}
	if (data->floor.xpm == NULL && data->ceiling.xpm)
	{
		if (!op->ignore)
			print_error(
			"Need floor texture to display the floor and ceiling.", true);
	}
	if (data->floor.color == -1)
		data->floor.color = GREEN;
	if (data->ceiling.color == -1)
		data->ceiling.color = CIAN;
}

int		check_textures(t_parse *data)
{
	if (data->xpm[NO] == NULL)
		return (return_message_i("NO texture not found.", NULL, 1));
	if (data->xpm[SO] == NULL)
		return (return_message_i("SO texture not found.", NULL, 1));
	if (data->xpm[EA] == NULL)
		return (return_message_i("EA texture not found.", NULL, 1));
	if (data->xpm[WE] == NULL)
		return (return_message_i("WE texture not found.", NULL, 1));
	return (0);
}

void	check_resolution(int *x, int *y, void *mlx, t_optis *op)
{
	if (*x < 100 || *y < 100)
	{
		if (!op->ignore)
			print_error("Resolution Too Low | Set to 100x100", true);
		*x = 100;
		*y = 100;
	}
	if (*x < 500 || *y < 500)
	{
		if (!op->ignore)
			print_error("Low resolution ! Map and FPS is displayed from the \
resolution 500x500", true);
	}
	check_screen_size(x, y, mlx, op);
	if (*x != 1440 || *y != 900)
	{
		if (!op->ignore)
			print_error("Bad resolution ! To display the bonus game, \
put the resolution 1440x900 in your .cub file", true);
	}
}

void	check_screen_size(int *x, int *y, void *mlx, t_optis *op)
{
	t_vec2i maxres;

	mlx_get_screen_size(mlx, &maxres.x, &maxres.y);
	if (*x > maxres.x || *y > maxres.y)
	{
		*x = maxres.x;
		*y = maxres.y;
		if (!op->ignore)
		{
			ft_putstr_fd(ORANGE_ERROR, 1);
			ft_putendl_fd("WARNING !", 1);
			ft_printf("Resolution Too High | Set to your screen size: %dx%d\n"
			, *x, *y);
			ft_putendl_fd("-", 1);
			ft_putstr_fd(RESET_ERROR, 1);
		}
	}
}
