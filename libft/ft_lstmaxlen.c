/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmaxlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:46:15 by csapt             #+#    #+#             */
/*   Updated: 2020/10/20 01:41:17 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmaxlen(t_list **maplist)
{
	size_t	x;
	t_list	*temp;

	x = 0;
	temp = *maplist;
	while (temp)
	{
		if (x < ft_strlen((char*)temp->content))
			x = ft_strlen((char*)temp->content);
		temp = temp->next;
	}
	return (x);
}
