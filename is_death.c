/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:24:50 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/15 19:25:53 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_rip(t_arg philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo.n_philo)
		{
			if (philo.philos[i].cmeal == philo.neat_philo)
				return 1;
			if ((get_current_t()
					- philo.philos[i].last_meal) >= philo.trip_philo)
			{
				printf("%lld %d is dead\n", get_current_t()
					- philo.philos[i].start_time, philo.philos[i].id);
				i = -1;
				while (++i < philo.n_philo)
					pthread_mutex_destroy(&philo.fork[i]);
				pthread_mutex_destroy(&philo.protect_print);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
