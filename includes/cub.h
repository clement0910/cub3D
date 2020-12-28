/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:58:35 by csapt             #+#    #+#             */
/*   Updated: 2020/12/28 16:52:00 by csapt            ###   ########lyon.fr   */
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
	t_optis			op;
	t_parse			data;
	t_game			*game;
}					t_global;

int					init_xpm(t_parse *data);
void				init_raystruct(t_parse *data, t_game *game);
void				init_ray_so_no(t_parse *data, t_game *game);
void				init_ray_ea_we(t_parse *data, t_game *game);
void				init_precalculated_rc(t_parse *data, t_game *game);
void				print_lstmap(t_list **spritelist, t_parse *data);
void				ft_free_static_tab(char **tab, int size);
void				init_parse_struct(t_parse *data);
/*
**					INIT FUNC
*/
void				init_parse(t_global *env, int ac, char **av);
void				init_bonus(t_global *env);
void				init_game(t_global *env);

int					loop(t_global *env);
int					loop_bonus(t_global *env);

int					close_window(t_global *env);

void				start_button(t_global *env, int x, int y);
void				menu_game(t_global *env);
void				quit_button(t_global *env, int x, int y);

/*
**					ERROR/QUIT
*/
void				error_cub(char *error, t_global *env);
void				free_cub(t_global *env, int exit);
void				free_lst_sinfo(t_sinfo_lst **s_info);
void				free_spritei(t_spritei *s_info, int x);

/*
**					DEBUG
*/
void				print_tab(char **tab); //review
void				ft_printdata(t_parse *data, t_list **maplist,
					t_sinfo_lst **s_info);
void				print_lst(t_list **maplist);
void				print_lst_sprite(t_sinfo_lst **s_info);
void				print_spritei(t_spritei s_info);
void				print_lstmap(t_list **spritelist, t_parse *data);
/*
**					PRINT MESSAGE
*/
void				print_error(char *error, bool warn);
void				*return_message(char *error, char *details);
int					return_message_i(char *error, char *details, int err);
int					return_message_c(char *error, char c, int err);

void				check_resolution(int *x, int *y, void *mlx);
void				check_ceilingandfloor(t_parse *data, t_optis *op);

void				init_bmp(t_global *env);
int					*int_to_bmp(t_global *env);
void				start_bmp(t_global *env);
void				main_map(t_parse *data, t_img *img, t_raycast *rc);
void				print_map(t_parse *data, t_img *img, int ratio, t_vec2i mapwrite);
void				print_player(t_parse *data, t_img *img, int ratio, t_vec2i mapwrite);
void				print_square(t_img *img, int color, t_vec2i mapwrite,
						int	ratio);
void				calcul_mapsize(t_parse *data, t_vec2i *mapwrite, int *ratio);

void				print_line(t_vec2i start, t_vec2i end, t_img *img);
void				print_line_high(t_vec2i start, t_vec2i end, t_img *img);
void				print_line_low(t_vec2i start, t_vec2i end, t_img *img);

void				resume_game(t_global *env);
void				screen_button(t_global *env, int x, int y);
void				settings_button(t_global *env, int x, int y);
void				settings_menu(t_global *env);
void				return_settings(t_global *env);
void				lowcub_settings(t_global *env);

void				move_player(t_parse *data, t_raycast *rc, t_keys *events);
void				fill_header(t_bmpfileheader *bfh, t_bmpinfoheader *bih, t_parse *data);

void				init_line_low(t_vec2i *line, t_vec2i start, t_vec2i end, int *yi);
void				init_line_high(t_vec2i *line, t_vec2i start, t_vec2i end, int *xi);

int					check_textures(t_parse *data);

void				check_options(int ac, char **av, t_global *env);

int					init_menu(t_parse *data);
int					init_resume(t_parse *data);
int					init_settings(t_parse *data);

int					create_xpm_bonus(t_global *env);
int					check_circled_map(t_parse *data, int x, int y);

int					check_details_map(t_parse *data, int x, int y, t_list **s_map);

void				calcul_print_map(t_vec2i *mapw, t_vec2i *coord, int xtmp, int ratio);
#endif
