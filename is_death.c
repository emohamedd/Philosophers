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

int	point_to_death(t_s_arg *philo)
{
	pthread_mutex_lock(&philo->data->protect_print);
	if (*philo->rip == 1)
	{
		pthread_mutex_unlock(&philo->data->protect_print);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->protect_print);
	return (0);
}

int	is_rip(t_arg *philo, int *h)
{
	int	i;
	int	all_eat;
	int	j;

	j = 0;
	all_eat = 0;
	i = 0;
	while (i < philo->n_philo)
	{
		if (philo->neat_philo != -1)
		{
			j = 0;
			while (j < philo->n_philo)
			{
				pthread_mutex_lock(&philo->protect_print);
				if (philo->philos[j].cmeal == philo->neat_philo)
				{
					pthread_mutex_unlock(&philo->protect_print);
					all_eat++;
				}
				pthread_mutex_unlock(&philo->protect_print);
				j++;
			}
			if (all_eat == philo->n_philo)
			{
				pthread_mutex_lock(&philo->protect_print);
				*h = 1;
				pthread_mutex_unlock(&philo->protect_print);
				return (1);
			}
		}
		if (time_to_die(philo, h))
			return (1);
		i++;
	}
	return (0);
}
