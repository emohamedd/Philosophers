/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:36:02 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/14 18:51:22 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *p)
{
    p_arg *philo;
    
    philo = (p_arg *)p;
    printf("%d\n", philo->id);
    return NULL;
}
int main(int ac, char **av)
{
    c_arg philo;

    if (ac < 5 || ac > 6)
    {
        printf("Error\n");
        return (1);
    }
   if(from_av_to_philo(&philo, ac, av + 1) == 0)
        return 1;
        
    philo.philos = malloc(sizeof(p_arg) * philo.n_philo);
    if (!philo.philos)
        return 200;
    int i = 0;
    while(i < philo.n_philo)
    {
        philo.philos[i].id = i + 1;
        philo.philos[i].start_time = 0;
        i++;
    }
    philo.threads = malloc(sizeof(pthread_t) * philo.n_philo);
    if (!philo.threads)
        return 200;
    i = 0;
    while(i < philo.n_philo)
    {
        pthread_create(&philo.threads[i], NULL, &routine, &philo.philos[i]);
        i++;
    }
    
}
