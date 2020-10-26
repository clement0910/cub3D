/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:10:41 by csapt             #+#    #+#             */
/*   Updated: 2020/10/26 17:49:47 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSE_H
# define CUB_PARSE_H

# include "libft.h"

typedef struct	s_spritei
{
	char		c;
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
int 			check_around(t_parse data, int x, int y);
int				check_validmap(t_parse *data);
void			free_parsing(t_parse *data);
void			filling_map(t_parse *data, t_list **maplist);
char			**filling_tab(t_list **list);

#endif
