/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:36:02 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/16 12:34:48 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_s_arg	*philo;

	philo = (t_s_arg *)p;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(philo->left_f);
		print_protect(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_f);
		print_protect(philo, "has taken a fork\n");
		print_protect(philo, "is eating\n");
		philo->cmeal++;
		// printf("from the thread wld qhba %d, kla %d mrat\n", philo->id, philo->cmeal);
		philo->last_meal = get_current_t();
		sleeping(philo->data->teat_philo);
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
		print_protect(philo, "is sleeping\n");
		sleeping(philo->data->tsleep_philo);
		print_protect(philo, "is thinking\n");
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_arg	philo;

	if (ac < 5 || ac > 6)
	{
		printf("Error\n");
		return (1);
	}
	if (from_av_to_philo(&philo, ac, av + 1) == 0)
		return (1);
	allocat(&philo);
	full_mutex(philo);
	pthread_mutex_init(&philo.protect_print, NULL);
	full_philo(philo);
	full_thread(philo);
	if (is_rip(philo))
		return (1);
	full_thread_join(philo);
}
