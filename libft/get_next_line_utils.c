/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:28:30 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 12:58:57 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t x;

	x = 0;
	while (str[x] != '\0' && str[x] != '\n')
		x++;
	return (x);
}

char	*ft_strdup_gnl(const char *s1)
{
	long	x;
	long	i;
	char	*strs;

	x = 0;
	i = ft_strlen_gnl((char*)s1);
	if (!(strs = malloc(i + 1 * sizeof(char))))
		return (0);
	while (x < i)
	{
		strs[x] = s1[x];
		x++;
	}
	strs[x] = '\0';
	return (strs);
}

char	*ft_strcpy(char *src, char *dst)
{
	size_t	x;

	x = 0;
	while (src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	while (dst[x] != '\0')
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}

char	*ft_strjoin_cpy(char *s1)
{
	size_t		x;
	char		*str;

	x = 0;
	if (!(str = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	while (s1[x] != '\0' && s1[x] != '\n')
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t		x;
	size_t		i;
	char		*str;

	x = 0;
	i = 0;
	if (s1 == NULL)
		return (ft_strjoin_cpy(s2));
	if (!(str = (char *)malloc(ft_strlen_gnl((char *)s1) +
	ft_strlen_gnl((char *)s2) + 1)))
		return (NULL);
	while (s1[x] != '\0' && s1[x] != '\n')
		str[i++] = s1[x++];
	free(s1);
	x = 0;
	while (s2[x] != '\0' && s2[x] != '\n')
		str[i++] = s2[x++];
	str[i] = '\0';
	return (str);
}
