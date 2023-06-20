/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:16:27 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/20 20:36:29 by emohamed         ###   ########.fr       */
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
	while (get_current_t() < end)
	{
		pthread_mutex_lock(&philo->data->protect_print);
		if (*philo->rip == 1)
		{
			pthread_mutex_unlock(&philo->data->protect_print);
			break ;
		}
		pthread_mutex_unlock(&philo->data->protect_print);
		usleep(100);
	}
}
