/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:44:50 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/18 15:00:25 by emohamed         ###   ########.fr       */
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
