/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:06:04 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:19:55 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	write_ray(t_raycast *rc, t_parse data, int x)
{
	rc->camx = 2 * x / (double)data.resx - 1;
	rc->ray.x = rc->dir.x + rc->plane.x * rc->camx;
	rc->ray.y = rc->dir.y + rc->plane.y * rc->camx;
	rc->map.x = (int)data.player.x;
	rc->map.y = (int)data.player.y;
}

void	initialdist(t_raycast *rc, t_parse data)
{
	rc->deltad.x = fabs(1 / rc->ray.x);
	rc->deltad.y = fabs(1 / rc->ray.y);
	rc->hit = 0;
	if (rc->ray.x < 0)
	{
		rc->stepx = -1;
		rc->sided.x = (data.player.x - rc->map.x) * rc->deltad.x;
	}
	else
	{
		rc->stepx = 1;
		rc->sided.x = (rc->map.x + 1.0 - data.player.x) * rc->deltad.x;
	}
	if (rc->ray.y < 0)
	{
		rc->stepy = -1;
		rc->sided.y = (data.player.y - rc->map.y) * rc->deltad.y;
	}
	else
	{
		rc->stepy = 1;
		rc->sided.y = (rc->map.y + 1.0 - data.player.y) * rc->deltad.y;
	}
}

void	dda_algo(t_raycast *rc, t_parse data)
{
	while (rc->hit == 0)
	{
		if (rc->sided.x < rc->sided.y)
		{
			rc->sided.x = rc->sided.x + rc->deltad.x;
			rc->map.x += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sided.y = rc->sided.y + rc->deltad.y;
			rc->map.y += rc->stepy;
			rc->side = 1;
		}
		if (data.map[rc->map.y][rc->map.x] == '1')
			rc->hit = 1;
	}
	if (rc->side == 0)
		rc->pwalld = (rc->map.x - data.player.x + (1 - rc->stepx) / 2) /
		rc->ray.x;
	else
		rc->pwalld = (rc->map.y - data.player.y + (1 - rc->stepy) / 2) /
		rc->ray.y;
	rc->lineh = (int)(data.resy / rc->pwalld);
}

void	start_draw(t_raycast *rc, t_parse data)
{
	rc->dstart = -rc->lineh / 2 + data.resy / 2;
	if (rc->dstart < 0)
		rc->dstart = 0;
	rc->dend = rc->lineh / 2 + data.resy / 2;
	if (rc->dend >= data.resy)
		rc->dend = data.resy - 1;
	if (rc->side == 1)
		rc->color = rc->ray.y < 0 ? RED : BLUE;
	else
		rc->color = rc->ray.x < 0 ? YELLOW : MAGENTA;
}
