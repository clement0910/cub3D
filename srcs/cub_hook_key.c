/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:15:20 by csapt             #+#    #+#             */
/*   Updated: 2020/12/28 16:46:44 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_press(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		events->key_internal[keycode] = true;
	return (0);
}

int		key_release(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		events->key_internal[keycode] = false;
	return (0);
}

bool	get_key_press(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (events->key[keycode] && events->last_key[keycode] == false);
	return (false);
}

bool	get_key_release(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (events->key[keycode] == false && events->last_key[keycode]);
	return (false);
}

bool	get_key(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (events->key[keycode]);
	return (false);
}
