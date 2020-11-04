/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:59:51 by csapt             #+#    #+#             */
/*   Updated: 2020/11/04 22:05:01 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_raycast(t_game *game, t_parse data, t_optis op)
{
	int x;

	x = 0;
	while (x < data.resx)
	{
		init_ray(&game->rc, data, x);
		init_dist(&game->rc, data);
		dda_algo(&game->rc, data);
		start_draw(&game->rc, data);
		if (op.texture)
			draw_tex(game, data, x);
		game->rc.zbuffer[x] = game->rc.pwalld;
		write_rc(game, data, op, x);
		x++;
	}
}

void	write_rc(t_game *game, t_parse data, t_optis op, int x)
{
	int y;

	y = -1;
	if (op.ceilingandfloor == false)
		while (y++ < game->rc.dstart)
			write_pixel(game->game, x, y, data.ceiling.color);
	game->rc.dstart -= 1;
	if (op.texture == false)
		while (game->rc.dstart++ < game->rc.dend)
			write_pixel(game->game, x, game->rc.dstart, game->rc.color);
	y = game->rc.dend;
	if (op.ceilingandfloor == false)
		while (y++ < data.resy - 1)
			write_pixel(game->game, x, y, data.floor.color);
	//rc->dstart =- 1; GIANT MODE;
	//Check this func
}

void	write_pixel(t_img *image, int x, int y, int color)
{
    int		*dst;
	//Protect value and check if x and y are in image.
	dst = image->addr + (y * (image->line_length / 4) + x);
	*dst = color;
}

int		close_window(t_global *env)
{
	free_cub(env, 0);
	return (0);
}

void	ft_free_static_tab(char **tab, int size)
{
	int x;

	x = 0;
	if (!tab)
		return;
	if (size == 0)
		return ;
	while (x < size)
	{
		if (tab)
			free(tab[x]);
		x++;
	}
}

void	xpm_to_gif(t_game *game, t_parse data)
{
	int x;

	x = 0;
	while (x < data.nbsprite)
	{
		if (game->sprite[x]->xpm == (game->sprite[x]->nsprite - 1))
			game->sprite[x]->xpm = 0;
		if (game->sprite[x]->nsprite > 1)
			game->sprite[x]->xpm++;
		x++;
	}
}

void	control_events(t_parse *data, t_raycast *rc, t_keys events, t_optis *op)
{
	float	speedtmp;

	speedtmp = 0.08;
	if (get_key(KEY_SHIFT_LEFT, &events))
		speedtmp *= 2;
	if (get_key(KEY_W, &events))
		move_forward(data, rc, speedtmp);
	if (get_key(KEY_S, &events))
		move_backward(data, rc, speedtmp);
	if (get_key(KEY_A, &events))
		move_left(data, rc, speedtmp);
	if (get_key(KEY_D, &events))
		move_right(data, rc, speedtmp);
	if (get_key(KEY_LEFT, &events))
		rotate(rc, 0.06);
	if (get_key(KEY_RIGHT, &events))
		rotate(rc, -0.06);
	if (events.key_on[KEY_T]) //?
		op->texture = false;
	else
		op->texture = true;
}

int		check_parse(t_parse *data, t_optis *op)
{
	if (data->resx <= 0 || data->resy <= 0)
		return(return_message_int("Resolution Error", NULL, 1));
	if (data->floor.xpm == NULL && data->floor.color == -1)
		return(return_message_int("Floor Error | Put texture or int", NULL, 1));
	if (data->ceiling.xpm == NULL && data->ceiling.color == -1)
		return(return_message_int("Ceiling Error | Put texture or int", NULL, 1));
	if (data->xpm[NO] == NULL)
		return(return_message_int("NO Texture not found", NULL, 1));
	if (data->xpm[SO] == NULL)
		return(return_message_int("SO Texture not found", NULL, 1));
	if (data->xpm[EA] == NULL)
		return(return_message_int("EA Texture not found", NULL, 1));
	if (data->xpm[WE] == NULL)
		return(return_message_int("WE Texture not found", NULL, 1));
	if (data->map == NULL)
		return(return_message_int("Map not found", NULL, 1));
	if (data->nbspritei == 0)
		return(return_message_int("Sprite Error | 1 is mandatory", NULL, 1));
	if (data->floor.xpm && data->ceiling.xpm)
		op->ceilflooron = true;
	if (data->floor.xpm && data->ceiling.xpm == NULL)
		print_error("Need ceiling to display the floor and ceiling.", true);
	if (data->floor.xpm == NULL && data->ceiling.xpm)
		print_error("Need floor to display the floor and ceiling.", true);
	if (data->floor.color == -1)
		data->floor.color = GREEN; //change color
	if (data->ceiling.color == -1)
		data->ceiling.color = CIAN;
	return (0);
}

int		check_resolution(int *x, int *y, void *mlx)
{
	int		maxx;
	int		maxy;

	if (*x < 100 || *y < 100)
	{
		print_error("Resolution Too Low | Set to 100x100", true);
		*x = 100;
		*y = 100;
		return (0);
	}
	mlx_get_screen_size(mlx, &maxx, &maxy);
	if (*x > maxx || *y > maxy)
	{
		print_error("Resolution Too High | Set to ur screen size", true);
		*x = maxx;
		*y = maxy;
		return (0);
	}
	return (1);	
}

int	ft_atoi_resolution(char *str, int *x)
{
	size_t resultat;

	resultat = 0;
	while ((str[*x] >= 9 && str[*x] <= 13) || str[*x] == ' ')
		(*x)++;
	while (str[*x] >= '0' && str[*x] <= '9')
	{
		resultat = resultat * 10 + (str[*x] - 48);
		(*x)++;
	}
	while ((str[*x] >= 9 && str[*x] <= 13) || str[*x] == ' ')
		(*x)++;
	if ((str[*x] != '\0')
	&& (ft_isdigit(str[*x]) == 0 || resultat <= 0 || resultat > 2147483647))
		return (-2);
	return ((int)resultat);
}

int	ft_atoi_color(char *str, int *x)
{
	size_t resultat;

	resultat = 0;
	while ((str[*x] >= 9 && str[*x] <= 13) || str[*x] == ' ')
		(*x)++;
	while (str[*x] >= '0' && str[*x] <= '9')
	{
		resultat = resultat * 10 + (str[*x] - 48);
		(*x)++;
	}
	while ((str[*x] >= 9 && str[*x] <= 13) || str[*x] == ' ')
		(*x)++;
	if (resultat < 0 || resultat > 2147483647)
		return (256);
	return ((int)resultat);	
}