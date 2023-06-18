/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:36:02 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/18 15:18:49 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_s_arg	*philo;

	philo = (t_s_arg *)p;
	if (philo->id % 2 == 0)
		usleep(200);
	loop_t(philo);
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
