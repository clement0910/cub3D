/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:49:08 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 21:50:57 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned long		get_time(void)
{
	struct timeval	actual_time;

	gettimeofday(&actual_time, NULL);
	return (actual_time.tv_sec * 1000000 + actual_time.tv_usec);
}

void				timer_restart(t_timer *timer)
{
	timer->ref_time = get_time();
	timer->elapsed_time = 0;
	timer->pause = false;
}

unsigned long		timer_get_microseconds(t_timer *timer)
{
	return (get_time() - timer->ref_time);
}

unsigned long		timer_get_milliseconds(t_timer *timer)
{
	return (timer_get_microseconds(timer) / 1000);
}

double				timer_get_seconds(t_timer *timer)
{
	return ((double)timer_get_microseconds(timer) / 1000000);
}
