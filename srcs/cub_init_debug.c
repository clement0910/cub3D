/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:04:17 by csapt             #+#    #+#             */
/*   Updated: 2021/01/02 17:57:31 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		init_debugstr(t_parse *data)
{
	if (!(data->debug = ft_calloc(14, sizeof(char*))))
		return (1);
	if (init_debugstr_tex(data))
		return (1);
	if (!(data->debug[8] = str_from_int(data->resx, data->resy,
			"RES:")))
		return (1);
	if (init_debugstr_colorxpm(data))
		return (1);
	data->debug[13] = NULL;
	return (0);
}

int		init_debugstr_tex(t_parse *data)
{
	if (!(data->debug[NO] = ft_strjoin("NO: ", data->xpm[NO])))
		return (1);
	if (!(data->debug[SO] = ft_strjoin("SO: ", data->xpm[SO])))
		return (1);
	if (!(data->debug[EA] = ft_strjoin("EA: ", data->xpm[EA])))
		return (1);
	if (!(data->debug[WE] = ft_strjoin("WE: ", data->xpm[WE])))
		return (1);
	if (!(data->debug[4] = ft_strjoin("NO: ", "YELLOW")))
		return (1);
	if (!(data->debug[5] = ft_strjoin("SO: ", "PINK")))
		return (1);
	if (!(data->debug[6] = ft_strjoin("EA: ", "BLUE")))
		return (1);
	if (!(data->debug[7] = ft_strjoin("WE: ", "RED")))
		return (1);
	return (0);
}

int		init_debugstr_colorxpm(t_parse *data)
{
	char *tmp;

	if (data->ceiling.xpm)
	{
		if (!(data->debug[9] = ft_strjoin("Ceiling: ", data->ceiling.xpm)))
			return (1);
	}
	if (data->floor.xpm)
	{
		if (!(data->debug[10] = ft_strjoin("Floor: ", data->floor.xpm)))
			return (1);
	}
	if (!(tmp = ft_itoa(data->ceiling.color)))
		return (1);
	if (!(data->debug[11] = ft_strjoin("Ceiling: ", tmp)))
		return (freestr_return(tmp, 1));
	free(tmp);
	if (!(tmp = ft_itoa(data->floor.color)))
		return (1);
	if (!(data->debug[12] = ft_strjoin("Floor: ", tmp)))
		return (freestr_return(tmp, 1));
	free(tmp);
	return (0);
}

char	*init_str_from_int(t_vec2i *len, int *lenstr, char *desc, t_vec2i coord)
{
	char *str;

	*lenstr = ft_strlen((char*)desc);
	len->x = ft_ullintlen((int)coord.x, "0123456789");
	len->y = ft_ullintlen((int)coord.y, "0123456789");
	if (!(str = malloc(*lenstr + len->x + len->y + 7)))
		return (NULL);
	ft_strcpy_cub(desc, str);
	return (str);
}

char	*str_from_int(int x, int y, char *desc)
{
	char	*str;
	char	*tmp;
	int		lenstr;
	t_vec2i len;

	if (!(str = init_str_from_int(&len, &lenstr, desc, (t_vec2i){x, y})))
		return (NULL);
	ft_strcpy_cub(" X:", str + lenstr);
	if (!(tmp = ft_itoa(x)))
	{
		free(str);
		return (NULL);
	}
	ft_strcpy_cub(tmp, str + lenstr + 3);
	free(tmp);
	ft_strcpy_cub(" Y:", str + lenstr + 3 + len.x);
	if (!(tmp = ft_itoa(y)))
	{
		free(str);
		return (NULL);
	}
	ft_strcpy_cub(tmp, str + lenstr + 3 + len.x + 3);
	free(tmp);
	str[lenstr + len.x + len.y + 6] = '\0';
	return (str);
}
