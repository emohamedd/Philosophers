/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:45:00 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/20 12:03:26 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_die(t_arg *philo, int *h)
{
	int			i;
	long long	period;

	i = 0;
	pthread_mutex_lock(&philo->protect_print);
	period = (get_current_t() - philo->philos[i].last_meal);
	pthread_mutex_unlock(&philo->protect_print);
	if (period >= philo->trip_philo)
	{
		pthread_mutex_lock(&philo->protect_print);
		*h = 1;
		pthread_mutex_unlock(&philo->protect_print);
		printf("%lld %d is dead\n", get_current_t()
			- philo->philos[i].start_time, philo->philos[i].id);
		if (philo->n_philo == 1)
			pthread_mutex_unlock(philo->philos[i].left_f);
		return (1);
	}
	return (0);
}
