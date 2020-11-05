/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_maputils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:23:51 by csapt             #+#    #+#             */
/*   Updated: 2020/11/05 13:52:23 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			malloc_map(char *line, t_list **maplist)
{
	t_list	*lsttemp;
	char	*temp;

	temp = NULL;
	if (*maplist == NULL)
	{
		if (!(temp = ft_strdup(line))
			|| !(*maplist = ft_lstnew(temp)))
		{
			free(temp);
			return (return_message_int("Allocation Error", NULL, 1));
		}
	}
	else
	{
		if (!(temp = ft_strdup(line))
			|| !(lsttemp = ft_lstnew(temp)))
		{
			free(temp);
			return (return_message_int("Allocation Error", NULL, 1));
		}
		ft_lstadd_back(maplist, lsttemp);
	}
	return (2);
}

int			check_map(char *line, t_list **maplist)
{
	int		x;

	x = 0;
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
		x++;
	if (line[x] == '0')
		return(return_message_int("Map need to be circled by 1.", NULL, 1));
	else if (line[x] == '1')
		return (malloc_map(line, maplist));
	else
		return (1);
}
