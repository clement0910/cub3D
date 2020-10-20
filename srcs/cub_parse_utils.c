/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:41:11 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 18:07:17 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	filling_tab(t_parse *data, t_list **maplist)
{
	int		x;
	t_list	*temp;

	x = 0;
	temp = *maplist;
	data->xmap = ft_lstmaxlen(maplist);
	data->map = malloc((ft_lstsize(temp) + 1) * sizeof(char*));
	while (temp)
	{
		data->map[x] = ft_calloc(data->xmap + 1, sizeof(char));
		ft_strlcpy(data->map[x], (char*)temp->content, data->xmap + 1);
		temp = temp->next;
		x++;
	}
	data->map[x] = NULL;
	data->ymap = ft_tablen(data->map);
}
