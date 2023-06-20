/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:45:00 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/20 20:32:03 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_die(t_s_arg *philo, int *h)
{
	int			i;
	long long	period;

	i = 0;
	pthread_mutex_lock(&philo->data->protect_print);
	period = (get_current_t() - philo->last_meal);
	pthread_mutex_unlock(&philo->data->protect_print);
	if (period >= philo->data->trip_philo)
	{
		pthread_mutex_lock(&philo->data->protect_print);
		*h = 1;
		pthread_mutex_unlock(&philo->data->protect_print);
		printf("%lld %d is dead\n", get_current_t()
			- philo->start_time, philo->id);
		if (philo->data->n_philo == 1)
			pthread_mutex_unlock(philo->left_f);
		return (1);
	}
	return (0);
}
