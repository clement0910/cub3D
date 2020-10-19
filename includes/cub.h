/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:58:35 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 15:05:40 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// MAKE CUB_H
#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_keys.h"

# include <stdio.h>
# include <sys/time.h> //FOR TIMER
# include <math.h> //FOR MATHS
# include <stdbool.h> //FOR BOOLEAN

typedef	struct		s_img
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				line_lenght_i;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef	struct		s_window
{
	void			*mlx;
	void			*win;
}					t_window;

typedef struct		s_menu
{
	t_img 			**menu;
	t_img			**resume;
	t_img			**settings;
	t_img			**logo;
}					t_menu;

typedef	struct		s_keys
{
	bool			key[KEY_MAX];
	bool			button[BUTTON_MAX];
	bool			key_on[KEY_MAX];
	bool			close;
}					t_keys;

typedef	struct		status_b
{
	bool			menu;
	bool			resume;
	bool			settings;
	bool			ui;
	bool			debug;
	bool			on;
	t_vec2i			cursor;
}					t_status_b;

typedef struct 		status
{
	bool			minimap;
	bool			ceilingandfloor;
	bool			texture;
	bool			fps;
}					t_status;

typedef struct		s_global
{
	t_window		win;
	t_menu			*main;
	t_keys			events;
	t_img			*cursor;
	t_status		status;
	t_status_b 		bonus;
}					t_global;

void				free_image_tab(int n, t_img **tab, void *mlx);
void				quit_cub(t_global *env);
t_img				**create_tab_xpm(void *mlx, int x, int y);
t_img				*create_xpm_image(void *mlx, char *tex_file);
t_img				*create_image(void *mlx, int x, int y);
void				free_image(t_img *image, void *mlx);	
void				close_window(t_global *env, int x, int y);		

bool				get_key(int keycode, t_keys *events);
int					key_press(int keycode, t_keys *events);
int					key_release(int keycode, t_keys *events);

bool				get_button(int keycode, int x, int y, t_keys *events);
int					button_press(int keycode, int x, int y, t_keys *events);
int					button_release(int keycode, int x, int y, t_keys *events);

int					quit_from_cross(t_global *env);
#endif
