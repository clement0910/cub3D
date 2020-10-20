/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_options.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:37 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:16:29 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_OPTIONS_H
# define CUB_OPTIONS_H

typedef struct		s_options_b
{
	bool			menu;
	bool			resume;
	bool			settings;
	bool			ui;
	bool			debug;
	bool			on;
}					t_options_b;

typedef struct		s_options
{
	bool			minimap;
	bool			ceilingandfloor;
	bool			texture;
	bool			fps;
	bool			game;
}					t_options;

#endif
