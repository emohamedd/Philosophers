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

int is_death(c_arg philo)
{
    int i = 0;
    while(1)
    {
        i = 0;
        while(i < philo.n_philo)
        { 
             if ((get_current_t() - philo.philos[i].last_meal) >= philo.trip_philo)
             {
                printf("%ld %d is dead\n", get_current_t() - philo.philos[i].start_time , philo.philos[i].id);
                return 1;
             }
            i++;
        }
    }
    return 0;
}