/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:15:20 by csapt             #+#    #+#             */
/*   Updated: 2020/10/18 23:50:12 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_press(int keycode, t_keys *events) 
{
	if (keycode >= 0 && keycode < KEY_MAX)
		events->tab[keycode] = true;
	return (0);
}

int		key_release(int keycode, t_keys *events) 
{
	if (keycode >= 0 && keycode < KEY_MAX)
		events->tab[keycode] = false;
	return (0);
}

int		button_press(int keycode, int x, int y, t_keys *events) 
{
	events->tabs[keycode] = true;
	return (0);
}

int		button_release(int keycode, int x, int y, t_keys *events) 
{
	events->tabs[keycode] = false;
	return (0);
}

bool	get_key(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return(events->tab[keycode]);
	return (false);
}

bool	get_key_press(int keycode, t_keys *events) 
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return(events->tab[keycode] && events->last_tab[keycode] == false);
	return (false);
}

bool	get_key_release(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return(events->tab[keycode] == false && events->last_tab[keycode]);
	return (false);
}

bool	get_button(int keycode, int x, int y, t_keys *events)
{
	if (keycode > 0 && keycode < BUTTON_MAX)
		return(events->tabs[keycode]);
	return (false);
}

bool	get_button_press(int keycode, int x, int y, t_keys *events)
{
	if (keycode > 0 && keycode < BUTTON_MAX)
		return(events->tabs[keycode] && events->last_tabs[keycode] == false);
	return (false);
}

bool	get_button_release(int keycode, int x, int y, t_keys *events)
{
	if (keycode > 0 && keycode < BUTTON_MAX)
		return(events->tabs[keycode] == false && events->last_tabs[keycode]);
	return (false);
}
