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

int is_rip(t_arg *philo, int *h) 
{
    int i;
    int all_eat;
    int j;

    j = 0;
    all_eat = 0;
    i = 0;
    while (i < philo->n_philo)
	 {
        pthread_mutex_lock(&philo->protect_death); 
        if (philo->neat_philo != -1) 
		{
            j = 0;
            while (j < philo->n_philo) 
			{
                if (philo->philos[j].cmeal == philo->neat_philo)
                    all_eat++;
                j++;
            }
            if (all_eat == philo->n_philo) 
			{
                *h = 1;
                pthread_mutex_unlock(&philo->protect_death); 
                return 1;
            }
        }
        pthread_mutex_unlock(&philo->protect_death); 
        if ((get_current_t() - philo->philos[i].last_meal) >= philo->trip_philo)
		 {
            pthread_mutex_lock(&philo->protect_death); 
            *h = 1;
            printf("%lld %d is dead\n", get_current_t() - philo->philos[i].start_time, philo->philos[i].id);
            pthread_mutex_unlock(&philo->protect_death); 
            return 1;
        }
        i++;
    }
    return 0;
}







