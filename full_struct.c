/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:53:06 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/15 19:45:11 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	full_philo(c_arg philo)
{
	long int	start_time;
	int			i;

	start_time = get_current_t();
	i = 0;
	while (i < philo.n_philo)
	{
		philo.philos[i].id = i + 1;
		philo.philos[i].start_time = start_time;
		philo.philos[i].last_meal = start_time;
		philo.philos[i].left_f = &philo.fork[i];
		philo.philos[i].right_f = &philo.fork[(i + 1) % philo.n_philo];
		philo.philos[i].data = &philo;
		i++;
	}
}

void	full_thread(c_arg philo)
{
	int	i;

	i = 0;
	while (i < philo.n_philo)
	{
		pthread_create(&philo.threads[i], NULL, &routine, &philo.philos[i]);
		usleep(10);
		i++;
	}
}

void	full_mutex(c_arg philo)
{
	int	i;

	i = 0;
	while (i < philo.n_philo)
	{
		pthread_mutex_init(&philo.fork[i], NULL);
		i++;
	}
}

void	full_thread_join(c_arg philo)
{
	int	i;

	i = 0;
	while (i < philo.n_philo)
	{
		pthread_join(philo.threads[i], NULL);
		i++;
	}
}
