/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:11:04 by csapt             #+#    #+#             */
/*   Updated: 2020/12/27 19:48:46 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		init_xpm(t_parse *data)
{
	if (init_menu(data))
		return (1);
	if (init_resume(data))
		return (1);
	if (init_settings(data))
		return (1);
	return (0);
}

int		init_menu(t_parse *data)
{
	if (!(data->tex = malloc(5 * sizeof(char*))))
		return (1);
	if (!(data->tex[0] = ft_strdup("./assets/ui/menu/menu.xpm")))
		return (1);
	if (!(data->tex[1] = ft_strdup("./assets/ui/menu/menu_p.xpm")))
		return (1);
	if (!(data->tex[2] = ft_strdup("./assets/ui/menu/menu_s.xpm")))
		return (1);
	if (!(data->tex[3] = ft_strdup("./assets/ui/menu/menu_q.xpm")))
		return (1);
	data->tex[4] = NULL;
	return (0);
}

int		init_resume(t_parse *data)
{
	if (!(data->resume = malloc(6 * sizeof(char*))))
		return (1);
	if (!(data->resume[0] = ft_strdup("./assets/ui/resume-menu/resume.xpm")))
		return (1);
	if (!(data->resume[1] = ft_strdup(
		"./assets/ui/resume-menu/resume-start.xpm")))
		return (1);
	if (!(data->resume[2] = ft_strdup(
		"./assets/ui/resume-menu/resume-settings.xpm")))
		return (1);
	if (!(data->resume[3] = ft_strdup(
		"./assets/ui/resume-menu/resume-quit.xpm")))
		return (1);
	if (!(data->resume[4] = ft_strdup(
		"./assets/ui/resume-menu/resume-screen.xpm")))
		return (1);
	data->resume[5] = NULL;
	return (0);
}

int		init_settings(t_parse *data)
{
	if (!(data->settings = malloc(3 * sizeof(char*))))
		return (1);
	if (!(data->settings[0] = ft_strdup("./assets/ui/settings/settings.xpm")))
		return (1);
	if (!(data->settings[1] = ft_strdup(
		"./assets/ui/settings/return_settings.xpm")))
		return (1);
	data->settings[2] = NULL;
	return (0);
}
