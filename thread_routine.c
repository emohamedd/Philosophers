/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:17:36 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/18 15:21:28 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_t(t_s_arg *philo)
{
	while (1)
	{
		if (point_to_death(philo) == 1)
			break ;
		pthread_mutex_lock(philo->left_f);
		print_protect(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_f);
		print_protect(philo, "has taken a fork\n");
		print_protect(philo, "is eating\n");
		pthread_mutex_lock(&philo->data->protect_print);
		philo->cmeal++;
		philo->last_meal = get_current_t();
		pthread_mutex_unlock(&philo->data->protect_print);
		sleeping(philo->data->teat_philo, philo);
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
		print_protect(philo, "is sleeping\n");
		sleeping(philo->data->tsleep_philo, philo);
		print_protect(philo, "is thinking\n");
	}
}
