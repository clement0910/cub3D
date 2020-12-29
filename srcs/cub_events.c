/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:51:19 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 22:07:47 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_player(t_parse *data, t_raycast *rc, t_keys *events)
{
	float	speedtmp;

	speedtmp = 0.08;
	if (get_key(KEY_SHIFT_LEFT, events))
		speedtmp *= 2;
	if (get_key(KEY_W, events))
		move_forward(data, rc, speedtmp);
	if (get_key(KEY_S, events))
		move_backward(data, rc, speedtmp);
	if (get_key(KEY_A, events))
		move_left(data, rc, speedtmp);
	if (get_key(KEY_D, events))
		move_right(data, rc, speedtmp);
	if (get_key(KEY_LEFT, events))
		rotate(rc, 0.06);
	if (get_key(KEY_RIGHT, events))
		rotate(rc, -0.06);
}

void	control_events(t_keys *events, t_optis *op)
{
	if (get_key_press(KEY_T, events))
		op->texture = !op->texture;
	if (get_key(KEY_TAB, events))
		op->minimap = true;
	else
		op->minimap = false;
	if (get_key_press(KEY_ESCAPE, events))
		op->resume = !op->resume;
	if (get_key_press(KEY_F, events))
		op->fps = !op->fps;
}

int		close_window(t_global *env)
{
	free_cub(env, 0);
	return (0);
}

void	xpm_to_gif(t_game *game, t_parse *data)
{
	int x;

	x = 0;
	while (x < data->nbsprite)
	{
		if (game->sprite[x]->xpm == (game->sprite[x]->nsprite - 1))
			game->sprite[x]->xpm = 0;
		if (game->sprite[x]->nsprite > 1)
			game->sprite[x]->xpm++;
		x++;
	}
}

void	poll_events(t_keys *events)
{
	ft_memcpy(events->last_button, events->button, BUTTON_MAX);
	ft_memcpy(events->last_key, events->key, KEY_MAX);
	ft_memcpy(events->key, events->key_internal, KEY_MAX);
	ft_memcpy(events->button, events->button_internal, BUTTON_MAX);
}
