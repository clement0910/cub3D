/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:19:12 by csapt             #+#    #+#             */
/*   Updated: 2020/06/02 10:24:39 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_index(char *str, int *x)
{
	int resultat;
	int neg;

	resultat = 0;
	neg = 1;
	while ((str[*x] >= 9 && str[*x] <= 13) || str[*x] == ' ')
		(*x)++;
	if (str[*x] == '-' || str[*x] == '+')
	{
		if (str[*x] == '-')
			neg = -1;
		(*x)++;
	}
	while (str[*x] >= '0' && str[*x] <= '9')
	{
		resultat = resultat * 10 + (str[*x] - 48);
		(*x)++;
	}
	return (resultat * neg);
}
