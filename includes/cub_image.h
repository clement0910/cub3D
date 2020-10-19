/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:54:15 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 17:48:03 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_IMAGE_H
# define CUB_IMAGE_H

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

/*
**					CREATE IMAGE
*/
t_img				**create_tab_xpm(void *mlx, int x, int y);
t_img				*create_xpm_image(void *mlx, char *tex_file);
t_img				*create_image(void *mlx, int x, int y);

/*
**					FREE IMAGE
*/
void				free_image_tab(int n, t_img **tab, void *mlx);
void				free_image(t_img *image, void *mlx);

#endif
