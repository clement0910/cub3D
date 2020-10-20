/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:51:23 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:16:09 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RAYCAST_H
# define CUB_RAYCAST_H

# include "libft.h"
# include "cub_parse.h"

typedef struct	s_raycast
{
	t_vec2f		dir;
	t_vec2f		plane;
	t_vec2f		ray;
	t_vec2f		sided;
	t_vec2f		deltad;
	t_vec2i		map;
	int			stepx;
	int			stepy;
	double		camx;
	double		pwalld;
	int			lineh;
	int			dstart;
	int			dend;
	int			color;
	int			hit;
	int			side;
	double		odirx;
	double		oplanex;
}				t_raycast;

/*
**					CONTROL PLAYER
*/
void			rotate(t_raycast *rc, double speed);
void			move_forward(t_parse *data, t_raycast *rc, double speed);
void			move_backward(t_parse *data, t_raycast *rc, double speed);
void			move_left(t_parse *data, t_raycast *rc, double speed);
void			move_right(t_parse *data, t_raycast *rc, double speed);

/*
**					CALCULATION RAYCAST
*/
void			write_ray(t_raycast *rc, t_parse data, int x);
void			initialdist(t_raycast *rc, t_parse data);
void			dda_algo(t_raycast *rc, t_parse data);
void			start_draw(t_raycast *rc, t_parse data);

void			write_pixel(t_img *image, int x, int y, int color);

#endif
