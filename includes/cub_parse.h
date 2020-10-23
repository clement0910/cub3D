/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:10:41 by csapt             #+#    #+#             */
/*   Updated: 2020/10/23 12:57:10 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSE_H
# define CUB_PARSE_H

# include "libft.h"


typedef struct	s_spritei
{
	int 		nsprite;
	char		**xpm_sprite;
	int			x;
	int			y;
}				t_spritei;

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
	//Sprite and GIF Here
	t_spritei	*info;
	char 		*sprite;
	char		**map;
	char		**tex; //in other struct
	t_vec2f		player;
	int			nbsprite;
}				t_parse;

/*
**					PARSING
*/
int				parse_xpmcolor(char *line, int *color, const char *details);
int				parse_textures(char *line, char **textures, const char *dir);
int				parse_resolution(char *line, void *mlx, int *x, int *y);

int				check_map(char *line, t_list **maplist);
int				check_line(char *line, void *mlx, t_parse *data);
int				cub_parse(int fd, t_parse *data, void *mlx);

void			free_parsing(t_parse *data);
void			filling_tab(t_parse *data, t_list **maplist);

#endif
