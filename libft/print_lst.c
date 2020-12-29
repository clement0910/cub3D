/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:07:57 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 20:08:16 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_lst(t_list **maplist)
{
	t_list *temp;

	temp = *maplist;
	while (temp)
	{
		ft_putendl_fd(temp->content, 1);
		temp = temp->next;
	}
}
