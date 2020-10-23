/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:13:39 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:13:40 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (!*lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		(*del)(temp->content);
		*lst = temp->next;
		free(temp);
		temp = *lst;
	}
	lst = NULL;
}
