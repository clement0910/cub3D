/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:57:53 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 17:47:19 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HOOK_H
# define CUB_HOOK_H

# include "mlx_keys.h"

# include <stdbool.h>

typedef	struct		s_keys
{
	bool			key[KEY_MAX];
	bool			button[BUTTON_MAX];
	bool			key_on[KEY_MAX];
}					t_keys;

/*
**					MANAGE KEY
*/
bool				get_key(int keycode, t_keys *events);
int					key_press(int keycode, t_keys *events);
int					key_release(int keycode, t_keys *events);

/*
**					MANAGE BUTTON
*/
bool				get_button(int keycode, int x, int y, t_keys *events);
int					button_press(int keycode, int x, int y, t_keys *events);
int					button_release(int keycode, int x, int y, t_keys *events);

#endif
