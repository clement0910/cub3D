/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_options.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:37 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 11:10:09 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_OPTIONS_H
# define CUB_OPTIONS_H

# include <stdbool.h>

typedef struct		s_options
{
	bool			minimap;
	bool			ceilingandfloor;
	bool			ceilflooron;
	bool			texture;
	bool			fps;
	bool			game;
	bool			debug;
	bool			ignore;
	bool			save;
	bool			menu;
	bool			resume;
	bool			settings;
	bool			ui;
	bool			on;
}					t_optis;

#endif
