/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:13:30 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:13:31 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (!alst || !new)
		return ;
	temp = *alst;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*alst = new;
	else
		temp->next = new;
}
