/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:36:02 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/17 17:59:54 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_s_arg	*philo;

	philo = (t_s_arg *)p;
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		pthread_mutex_lock(&philo->data->protect_print);
		if (*philo->rip == 1)
		{
			pthread_mutex_unlock(&philo->data->protect_print);
			break;
		}
		pthread_mutex_unlock(&philo->data->protect_print);
		
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
	return (NULL);
}

int	main(int ac, char **av)
{
	t_arg	philo;
	int		debug;

	debug = 0;
	if (ac < 5 || ac > 6)
	{
		printf("Error\n");
		return (1);
	}
	if (from_av_to_philo(&philo, ac, av + 1) == 0)
		return (1);
	allocat(&philo);
	full_mutex(&philo);
	pthread_mutex_init(&philo.protect_print, NULL);
	pthread_mutex_init(&philo.protect_death, NULL);
	full_philo(&philo, &debug);
	full_thread(&philo);
	while (1)
	{
		if (is_rip(&philo, &debug))
				break ;
	}
	full_thread_join(&philo);
	destroy_mutex(&philo);
}
