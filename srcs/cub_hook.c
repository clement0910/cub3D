/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:15:20 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 14:04:35 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_press(int keycode, t_keys *events) 
{
	if (keycode >= 0 && keycode < KEY_MAX)
		events->key[keycode] = true;
	return (0);
}

int		key_release(int keycode, t_keys *events) 
{
	if (keycode >= 0 && keycode < KEY_MAX)
	{
		events->key[keycode] = false;
		events->key_on[keycode] = !events->key_on[keycode];
	}
	return (0);
}

int		button_press(int keycode, int x, int y, t_keys *events) 
{
	if (keycode >= 0 && keycode < BUTTON_MAX)
		events->button[keycode] = true;
	return (0);
}

int		button_release(int keycode, int x, int y, t_keys *events) 
{
	if (keycode >= 0 && keycode < BUTTON_MAX)
		events->button[keycode] = false;
	return (0);
}

bool	get_key(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return(events->key[keycode]);
	return (false);
}

bool	get_button(int keycode, int x, int y, t_keys *events)
{
	if (keycode > 0 && keycode < BUTTON_MAX)
		return(events->button[keycode]);
	return (false);
}
