/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:16:27 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/17 13:29:54 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_t(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleeping(int n, t_s_arg *philo)
{
	long long	save_time;
	long long	end;

	save_time = get_current_t();
	end = n + save_time;
	pthread_mutex_lock(&philo->data->protect_death);
	while (get_current_t() <= end && !*philo->rip)
	pthread_mutex_unlock(&philo->data->protect_death);
		usleep(100);
}
