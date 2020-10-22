/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:30:08 by csapt             #+#    #+#             */
/*   Updated: 2020/10/22 18:23:38 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GAME_H
# define CUB_GAME_H

# include "cub_image.h"
# include "cub_parse.h"
# include "cub_hook.h"
# include "cub_options.h"

typedef struct		s_raycast
{
	t_vec2f			dir;
	t_vec2f			plane;
	t_vec2f			ray;
	t_vec2f			sided;
	t_vec2f			deltad;
	t_vec2i			map;
	int				stepx;
	int				stepy;
	double			camx;
	double			pwalld;
	int				lineh;
	int				dstart;
	int				dend;
	int				color;
	int				hit;
	int				side;
	double			odirx;
	double			oplanex;

	double			wallx;
	t_vec2i			tex;
	double			step;
	double			texpos;
}					t_raycast;

typedef struct		s_game
{
	t_img			*game;
	t_img			**textures;
	t_raycast		rc;
}					t_game;

typedef struct		s_cursor
{
	t_vec2i			pos;
	t_img			*img;
}					t_cursor;

typedef struct		s_menu
{
	t_img			**menu;
	t_img			**resume;
	t_img			**settings;
	t_img			**logo;
	t_cursor		*cur;
}					t_menu;

/*
**					CONTROL PLAYER
*/
void				rotate(t_raycast *rc, double speed);
void				move_forward(t_parse *data, t_raycast *rc, double speed);
void				move_backward(t_parse *data, t_raycast *rc, double speed);
void				move_left(t_parse *data, t_raycast *rc, double speed);
void				move_right(t_parse *data, t_raycast *rc, double speed);

/*
**					CALCULATION RAYCAST
*/
void				init_ray(t_raycast *rc, t_parse data, int x);
void				init_dist(t_raycast *rc, t_parse data);
void				dda_algo(t_raycast *rc, t_parse data);
void				start_draw(t_raycast *rc, t_parse data);

/*
**					PRINT RAYCAST
*/
void				main_raycast(t_game *game, t_parse data, t_options op);
void				draw_tex(t_game *g, t_parse data, int x);
void				write_pixel(t_img *image, int x, int y, int color);
void				write_rc(t_game *game, t_parse data, t_options op, int x);

void				control_events(t_parse *data, t_raycast *rc, t_keys events);

#endif