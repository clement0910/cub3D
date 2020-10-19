/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:24:58 by csapt             #+#    #+#             */
/*   Updated: 2020/10/19 17:26:23 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

bool	get_button(int keycode, int x, int y, t_keys *events)
{
	if (keycode > 0 && keycode < BUTTON_MAX)
		return (events->button[keycode]);
	return (false);
}
