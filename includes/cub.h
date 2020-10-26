/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:58:35 by csapt             #+#    #+#             */
/*   Updated: 2020/10/26 16:48:56 by csapt            ###   ########lyon.fr   */
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
# include "cub_options.h"
# include "cub_mlx.h"
# include "cub_game.h"
# include "cub_bmp.h"

# include <stdio.h>
# include <sys/time.h> //FOR TIMER
# include <math.h> //FOR MATHS
# include <stdbool.h> //FOR BOOLEAN

# define RED_ERROR "\033[1;31m"
# define RESET_ERROR "\033[0m"
# define ORANGE_ERROR "\033[01;33m"

# define NO 0
# define SO 1
# define EA 2 
# define WE 3

typedef struct		s_global
{
	t_window		win;
	t_menu			*main;
	t_keys			events;
	t_options		op;
	t_parse			data;
	t_game			*game;
}					t_global;

void				init_text(t_global *env);
void				init_raystruct(t_global *env);
void				ft_free_static_tab(char **tab, int size);
void				init_sprite(t_global *env);
/*
**					INIT FUNC
*/				
void				init_parse(t_global *env, int ac, char **av);
void				init_bonus(t_global *env);
void				init_game(t_global *env);

int					loop(t_global *env);
int					loop_bonus(t_global *env);

int					close_window(t_global *env);

void				start_game(t_global *env, int x, int y);
void				menu_game(t_global *env);
void				quit_button(t_global *env, int x, int y);

/*
**					ERROR/QUIT
*/
void				error_cub(char *error, t_global *env);
void				free_cub(t_global *env, int exit);

/*
**					DEBUG
*/
void				print_tab(char **tab);
void				ft_printdata(t_parse data, t_list **maplist, t_sprite_list **sprite);
void				print_lst(t_list **maplist);
void				print_lst_sprite(t_sprite_list **list);
/*
**					PRINT MESSAGE
*/
void				print_error(char *error, bool warn);
void				*return_message(char *error, char *details);

t_list	*malloc_textures_list(char *line, int x, int y);
t_sprite_desc *malloc_sprite_desc(char *line, int x, int y);

#endif
