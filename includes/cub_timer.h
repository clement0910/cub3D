/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_timer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:45:33 by csapt             #+#    #+#             */
/*   Updated: 2020/12/29 22:02:28 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_TIMER_H
# define CUB_TIMER_H

typedef struct		s_timer
{
	unsigned long	ref_time;
	unsigned long	elapsed_time;
	bool			pause;
}					t_timer;

typedef	struct		s_frame
{
	int				fps;
	int				lastfps;
	t_timer			timer;
}					t_frame;

unsigned long		get_time(void);
void				timer_restart(t_timer *timer);
unsigned long		timer_get_microseconds(t_timer *timer);
unsigned long		timer_get_milliseconds(t_timer *timer);
double				timer_get_seconds(t_timer *timer);

#endif
