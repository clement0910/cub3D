/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:52:04 by csapt             #+#    #+#             */
/*   Updated: 2020/06/16 15:42:38 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 32

int		get_next_zero(char **str, char *buf);
int		get_next_backn(char **str, char *buf, int fd, long *error);
int		get_next_line(int fd, char **line);
size_t	ft_strlen_gnl(char *str);
char	*ft_strdup_gnl(char *str);
char	*ft_strcpy(char *src, char *dst);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_check_index(char *buf);
char	*ft_strjoin_cpy(char *s1);

#endif
