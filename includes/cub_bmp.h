/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:44:01 by csapt             #+#    #+#             */
/*   Updated: 2020/11/06 17:09:00 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BMP_H
# define CUB_BMP_H

#include <stdint.h>

#pragma pack(push, 1)

typedef struct	s_bmpfileheader
{
	unsigned char	signature[2];
	int				bmp_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset;
}				t_bmpfileheader;

typedef struct	s_bmpinfoheader
{
	unsigned int	header_size;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_pxl;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	res_x;
	unsigned int	res_y;
	unsigned int	color_img;
	unsigned int	color_important;
	unsigned int	red_mask;
	unsigned int	green_mask;
	unsigned int	blue_mask;
	unsigned int	alpha_mask;
}				t_bmpinfoheader;

#pragma pack(pop)

#endif