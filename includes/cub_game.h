/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:30:08 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 19:12:57 by csapt            ###   ########lyon.fr   */
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

	double			*zbuffer;
	t_vec2d			sprite;
	double			invdet;
	t_vec2d			transform;
	int				spritesx;
	t_vec2i			spritesize;
	t_vec2i			dstart_s;
	t_vec2i			dend_s;
	int				pre1;
	int				pre2;
	int				pre3;
	int				pre4;
	int				pre5;
	int				pre6;
	float			pre7;
	int				d;

	t_vec2f			ray0;
	t_vec2f			ray1;
	int				posycenter;
	float			posz;
	float			rowdistance;
	t_vec2f			floorstep;
	t_vec2f			floor;
	t_vec2i			cell;
	int				tx;
	int				ty;
}					t_raycast;

typedef struct		s_game
{
	t_img			*game;
	t_img			**textures;
	t_raycast		rc;
	t_sprite		**sprite;
	t_img			*ceiling;
	t_img			*floor;
	int				*spriteorder;
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
	t_img			*logo;
	t_cursor		*cur;
	t_img			*map;
	t_img			*on;
	t_img			*hud;
}					t_menu;

/*
**					CONTROL PLAYER
*/
void				rotate(t_raycast *rc, double speed);
void				move_forward(t_parse *data, t_raycast *rc, double speed);
void				move_backward(t_parse *data, t_raycast *rc, double speed);
void				move_left(t_parse *data, t_raycast *rc, double speed);
void				move_right(t_parse *data, t_raycast *rc, double speed);
void				move_player(t_parse *data, t_raycast *rc, t_keys *events);
/*
**					CALCULATION RAYCAST
*/
void				init_ray(t_raycast *rc, t_parse *data, int x);
void				init_dist(t_raycast *rc, t_parse *data);
void				dda_algo(t_raycast *rc, t_parse *data);
void				start_draw(t_raycast *rc, t_parse *data);

/*
**					PRINT RAYCAST
*/
void				main_raycast(t_game *game, t_parse *data, t_optis op);
void				draw_tex(t_game *g, t_parse *data, int x);
void				write_pixel(t_img *image, int x, int y, int color);
void				write_rc(t_game *game, t_parse *data, t_optis op, int x);

/*
**					CALCULATION & PRINT SPRITE
*/
void				sort_sprite(t_parse *data, t_game *game);
void				sprite_matrix(t_game *game, t_parse *data, int i);
void				calcul_sprite_xy(t_game *game, t_parse *data,
					int *stripe);
void				main_sprite(t_game *game, t_parse *data);
void				write_sprite(t_game *game, t_parse *data, int i,
					int *stripe);
void				color_sprite(t_game *game, int i);

/*
**					CALCULATION & PRINT FLOOR
*/
void				main_floor(t_game *game, t_parse *data);
void				calcul_floor(t_game *game);
void				calcul_floor_step(t_game *game, t_parse *data, int y);
void				xpm_to_gif(t_game *game, t_parse *data);
void				control_events(t_keys *events, t_optis *op);

/*
**					CALCULATION & PRINT MAP
*/
void				main_map(t_parse *data, t_img *img, t_raycast *rc);
void				print_map(t_parse *data, t_img *img, int ratio,
					t_vec2i mapwrite);
void				print_player(t_parse *data, t_img *img, int ratio,
					t_vec2i mapwrite);
void				print_square(t_img *img, int color, t_vec2i mapwrite,
					int	ratio);
void				calcul_print_map(t_vec2i *mapw, t_vec2i *coord, int xtmp,
					int ratio);
void				calcul_mapsize(t_parse *data, t_vec2i *mapwrite,
					int *ratio);

/*
**					BRESENHAM’S ALGORITHM
*/
void				init_line_low(t_vec2i *line, t_vec2i start, t_vec2i end,
					int *yi);
void				init_line_high(t_vec2i *line, t_vec2i start, t_vec2i end,
					int *xi);
void				print_line(t_vec2i start, t_vec2i end, t_img *img);
void				print_line_high(t_vec2i start, t_vec2i end, t_img *img);
void				print_line_low(t_vec2i start, t_vec2i end, t_img *img);

#endif
