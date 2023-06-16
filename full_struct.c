/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:53:06 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/16 17:13:00 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	full_philo(t_arg *philo, int *h)
{
	long long	start_time;
	int			i;

	start_time = get_current_t();
	i = 0;
	while (i < philo->n_philo)
	{
		philo->philos[i].rip = h;
		philo->philos[i].cmeal = 0;
		philo->philos[i].id = i + 1;
		philo->philos[i].start_time = start_time;
		philo->philos[i].last_meal = start_time;
		philo->philos[i].left_f = &philo->fork[i];
		philo->philos[i].right_f = &philo->fork[(i + 1) % philo->n_philo];
		philo->philos[i].data = philo;
		i++;
	}
}

void	full_thread(t_arg *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		pthread_create(&philo->threads[i], NULL, &routine, &philo->philos[i]);
		usleep(10);
		i++;
	}
}

void	full_mutex(t_arg *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		i++;
	}
}

void	full_thread_detach(t_arg *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		pthread_detach(philo->threads[i]);
		i++;
	}
}

void	full_thread_join(t_arg *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		pthread_join(philo->threads[i], NULL);
		i++;
	}
}

void	destroy_mutex(t_arg *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		i++;
	}
}
