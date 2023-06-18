/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:53:06 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/18 14:45:16 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	pthread_mutex_destroy(&philo->protect_death);
	pthread_mutex_destroy(&philo->protect_print);
}
