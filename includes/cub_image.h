/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:54:15 by csapt             #+#    #+#             */
/*   Updated: 2020/10/22 18:59:02 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_IMAGE_H
# define CUB_IMAGE_H

# include "libft.h"

typedef	struct		s_img
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				line_length_i;
	int				endian;
	int				width;
	int				height;
}					t_img;

/*
**					CREATE IMAGE
*/
t_img				**create_tab_xpm(void *mlx, int size, char **xpm);
t_img				*create_xpm_image(void *mlx, char *tex_file);
t_img				*create_image(void *mlx, int x, int y);

/*
**					FREE IMAGE
*/
void				free_image_tab(int n, t_img **tab, void *mlx);
void				free_image(t_img *image, void *mlx);

void				write_pixel(t_img *image, int x, int y, int color);
#endif
