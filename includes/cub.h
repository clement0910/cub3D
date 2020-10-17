/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:58:35 by csapt             #+#    #+#             */
/*   Updated: 2020/10/17 14:13:49 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// MAKE CUB_H
#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "ui_cub.h"
# include "get_next_line.h"
# include "mlx.h"

# include <sys/time.h> //FOR TIMER
# include <math.h> //FOR MATHS

typedef	struct	s_img
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			line_lenght_i;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef	struct	s_window
{
	void		*mlx;
	void		*win;
}				t_window;

typedef struct		s_menu
{
	t_img 			**menu;
	t_img			**resume;
	t_img			**settings;
	t_img			**logo;
}					t_menu;

typedef struct		s_global
{
	t_window		win;
	t_menu			*main;
}					t_global;

t_img				**create_tab_xpm(void *mlx, int x, int y);
t_img				*create_xpm_image(void *mlx, char *tex_file);
t_img				*create_image(void *mlx, int x, int y);
void				free_image(t_img *image, void *mlx);			
#endif
