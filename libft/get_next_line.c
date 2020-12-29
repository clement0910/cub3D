/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:28:37 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 13:00:08 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_index(char *buf)
{
	long	x;

	x = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
		{
			x++;
			return (x);
		}
		x++;
	}
	return (-1);
}

int		get_next_zero(char **str, char *buf)
{
	long x;

	x = ft_check_index(buf);
	if (x > 0)
		ft_strcpy(buf + x, buf);
	*str = ft_strjoin_gnl(*str, buf);
	if (ft_chrcmp(buf, '\n') == 0)
		return (1);
	return (0);
}

int		get_next_backn(char **str, char *buf, int fd, long *error)
{
	if (BUFFER_SIZE <= 0)
		return (-1);
	*error = read(fd, buf, BUFFER_SIZE);
	if (fd < 0 || *error < 0)
		return (-1);
	buf[*error] = '\0';
	*str = ft_strjoin_gnl(*str, buf);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		buf[(BUFFER_SIZE * 1) + 1];
	char			*str;
	long			error;

	str = NULL;
	if ((error = 1) == 1 && (fd < 0 || !line || BUFFER_SIZE <= 0))
		return (-1);
	if (ft_chrcmp(buf, '\n') == 0)
	{
		if (get_next_zero(&str, buf) == 1)
		{
			*line = ft_strdup(str);
			free(str);
			return (1);
		}
	}
	while (ft_chrcmp(buf, '\n') == 1 && error != 0)
	{
		get_next_backn(&str, buf, fd, &error);
		if (error < 0)
			return (-1);
	}
	*line = ft_strdup(str);
	free(str);
	return ((error == 0) ? 0 : 1);
}
