/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:08:31 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:20:35 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_backward(t_parse *data, t_raycast *rc, double speed)
{
	if (data->map[(int)data->player.y]
		[(int)(data->player.x - rc->dir.x * speed)] != '1')
		data->player.x -= rc->dir.x * speed;
	if (data->map[(int)(data->player.y - rc->dir.y * speed)]
		[(int)data->player.x] != '1')
		data->player.y -= rc->dir.y * speed;
}

void	move_forward(t_parse *data, t_raycast *rc, double speed)
{
	if (data->map[(int)data->player.y]
		[(int)(data->player.x + rc->dir.x * speed)] != '1')
		data->player.x += rc->dir.x * speed;
	if (data->map[(int)(data->player.y + rc->dir.y * speed)]
		[(int)data->player.x] != '1')
		data->player.y += rc->dir.y * speed;
}

void	move_left(t_parse *data, t_raycast *rc, double speed)
{
	if (data->map[(int)data->player.y]
		[(int)(data->player.x - rc->plane.x * speed)] != '1')
		data->player.x -= rc->plane.x * speed;
	if (data->map[(int)(data->player.y - rc->plane.y * speed)]
		[(int)data->player.x] != '1')
		data->player.y -= rc->plane.y * speed;
}

void	move_right(t_parse *data, t_raycast *rc, double speed)
{
	if (data->map[(int)data->player.y]
		[(int)(data->player.x + rc->plane.x * speed)] != '1')
		data->player.x += rc->plane.x * speed;
	if (data->map[(int)(data->player.y + rc->plane.y * speed)]
		[(int)data->player.x] != '1')
		data->player.y += rc->plane.y * speed;
}

void	rotate(t_raycast *rc, double speed)
{
	rc->odirx = rc->dir.x;
	rc->dir.x = rc->dir.x * cos(speed) - rc->dir.y * sin(speed);
	rc->dir.y = rc->odirx * sin(speed) + rc->dir.y * cos(speed);
	rc->oplanex = rc->plane.x;
	rc->plane.x = rc->plane.x * cos(speed) - rc->plane.y * sin(speed);
	rc->plane.y = rc->oplanex * sin(speed) + rc->plane.y * cos(speed);
}
