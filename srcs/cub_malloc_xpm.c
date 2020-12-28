/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_malloc_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:00:07 by csapt             #+#    #+#             */
/*   Updated: 2020/12/27 22:03:14 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		create_xpm_bonus(t_global *env)
{
	if (!(env->main->menu = create_tab_xpm(env->win.mlx, 4, env->data.tex)))
		return (1);
	if (!(env->main->resume = create_tab_xpm(env->win.mlx, 5,
	env->data.resume)))
		return (1);
	if (!(env->main->settings = create_tab_xpm(env->win.mlx, 2,
	env->data.settings)))
		return (1);
	if (!(env->main->cur->img = create_xpm_image(env->win.mlx,
	"assets/ui/cursor/cursor.xpm")))
		return (1);
	if (!(env->main->map = create_xpm_image(env->win.mlx,
	"assets/ui/map/cardinal-point.xpm")))
		return (1);
	if (!(env->main->on = create_xpm_image(env->win.mlx,
	"assets/ui/settings/whitepixel.xpm")))
		return (1);
	return (0);
}
