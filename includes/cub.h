/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:58:35 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 01:45:22 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_keys.h"
# include "cub_image.h"
# include "cub_hook.h"
# include "cub_parse.h"
# include "cub_debug.h"

# include <stdio.h>
# include <sys/time.h> //FOR TIMER
# include <math.h> //FOR MATHS
# include <stdbool.h> //FOR BOOLEAN

typedef	struct		s_window
{
	void			*mlx;
	void			*win;
}					t_window;

typedef struct		s_menu
{
	t_img			**menu;
	t_img			**resume;
	t_img			**settings;
	t_img			**logo;
}					t_menu;

typedef struct		s_options_b
{
	bool			menu;
	bool			resume;
	bool			settings;
	bool			ui;
	bool			debug;
	bool			on;
}					t_options_b;

typedef struct		s_options
{
	bool			minimap;
	bool			ceilingandfloor;
	bool			texture;
	bool			fps;
}					t_options;

typedef struct		s_cursor
{
	t_vec2i			pos;
	t_img			*img;
}					t_cursor;

typedef struct		s_global
{
	t_window		win;
	t_menu			*main;
	t_keys			events;
	t_cursor		*cur;
	t_options		op;
	t_options_b		opb;
	t_parse			data;
}					t_global;

void				quit_cub(t_global *env);
void				close_window(t_global *env, int x, int y);
void				menu_game(t_global *env);
int					quit_from_cross(t_global *env);
int					loop(t_global *env);
int					loop_bonus(t_global *env);

#endif
