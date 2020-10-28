/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:10:41 by csapt             #+#    #+#             */
/*   Updated: 2020/10/28 19:10:48 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSE_H
# define CUB_PARSE_H

# include "libft.h"
# include "cub_options.h"

typedef	t_list	t_sinfo_lst;
typedef	t_list	t_smap_lst;

typedef	struct	s_sprite_desc
{
	char		c;
	t_list		*textures;
}				t_sprite_desc;

typedef struct	s_spritei
{
	char		c;
	int			nsprite;
	char		**xpm_sprite;
}				t_spritei;

typedef	struct	s_spritem
{
	float		x;
	float		y;
	t_spritei	s_info;
}				t_spritem;

typedef	struct	s_colorxpm
{
	char		*xpm;
	int			color;
}				t_colorxpm;

typedef struct	s_parse
{
	int			xmap;
	int			ymap;
	char		orientation;
	int			resx;
	int			resy;
	char		*xpm[4];
	t_colorxpm	floor;
	t_colorxpm	ceiling;
	t_spritei	*s_info;
	t_spritem	*s_map;
	char		**map;
	char		**tex; //in other struct (bonus)
	char		*symbol;
	t_vec2f		player;
	int			nbsprite;
	int			nbspritei;
}				t_parse;

/*
**				PARSE PARAMS
*/
int				parse_xpmcolor(char *line, t_colorxpm *color,
				const char *details);
int				parse_textures(char *line, char **textures, const char *dir);
int				parse_resolution(char *line, void *mlx, int *x, int *y);
int				check_line(char *line, void *mlx, t_parse *data);

/*
**				PARSE SPRITESINFO
*/
int				check_spritesinfo(char *line, t_sinfo_lst **s_info);
int				new_spritesinfo(char *line, t_sinfo_lst **s_info);
int				addback_spritesinfo(char *line, t_sinfo_lst **s_info,
				int x, int y);
int				textures_of_sprites(char *line, t_sinfo_lst **s_info);
t_spritem		*malloc_smap(double x, double y, t_spritei s_info);
t_list			*malloc_texlist(char *line, int x, int y);
t_sprite_desc	*malloc_sdesc(char *line, int x, int y);
int				fill_spriteinfo(t_parse *data, t_sinfo_lst **s_info);
char			**fill_tab(t_list **list);

/*
**				PARSE MAP / VALID MAP
*/
int				check_map(char *line, t_list **maplist);
int				malloc_map(char *line, t_list **maplist);
int				check_around(t_parse data, int x, int y);
int				check_validmap(t_parse *data);
int				fill_map(t_parse *data, t_list **maplist);

/*
**				PARSE SPRITE
*/
int				fill_sprite(t_parse *data, t_list **sprite_list);
int				fill_symbol(t_parse *data);
int				check_pos_sprite(t_parse *data, char c, int x, int y,
				t_list **s_map);

/*
**				GLOBAL PARSE
*/
int				cub_parse(int fd, t_parse *data, void *mlx);
int				cub_parse_error(char *line, t_sinfo_lst **s_info,
				t_list **maplist, int *error);
int				cub_parse_clear(t_parse *data, t_list **maplist,
				t_sinfo_lst **s_info);

int				check_parse(t_parse *data, t_optis *op);
void			free_parsing(t_parse *data);

#endif
