/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:36:02 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/15 18:48:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *p)
{
    p_arg *philo;
    
    philo = (p_arg *)p;
    if (philo->id % 2 != 0)
        usleep(100);
    while (1)
    {
        pthread_mutex_lock(philo->left_f);
        pthread_mutex_lock(&philo->data->protect_print);
        printf("%ld %d has taken a fork\n", get_current_t() - philo->start_time , philo->id);
        pthread_mutex_unlock(&philo->data->protect_print);
        pthread_mutex_lock(philo->right_f);
        pthread_mutex_lock(&philo->data->protect_print);
        printf("%ld %d has taken a fork\n", get_current_t() - philo->start_time , philo->id);
        pthread_mutex_unlock(&philo->data->protect_print);
        pthread_mutex_lock(&philo->data->protect_print);
        printf("%ld %d is eating\n", get_current_t() - philo->start_time , philo->id);
        philo->last_meal = get_current_t();
        pthread_mutex_unlock(&philo->data->protect_print);
        sleeping(philo->data->teat_philo);
        pthread_mutex_unlock(philo->right_f);
        pthread_mutex_unlock(philo->left_f);
        pthread_mutex_lock(&philo->data->protect_print); 
        printf("%ld %d is sleeping\n", get_current_t() - philo->start_time , philo->id);
        pthread_mutex_unlock(&philo->data->protect_print);
        sleeping(philo->data->tsleep_philo);
        pthread_mutex_lock(&philo->data->protect_print);
        printf("%ld %d is thinking\n", get_current_t() - philo->start_time , philo->id);
        pthread_mutex_unlock(&philo->data->protect_print);
    }

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
    
    philo.fork = malloc(sizeof(pthread_mutex_t) * philo.n_philo);
    if (!philo.fork)
        return 300;
    int i = 0;
    while(i < philo.n_philo)
    {
        pthread_mutex_init(&philo.fork[i], NULL);
        i++;
    }
    pthread_mutex_init(&philo.protect_print, NULL);
    
    philo.philos = malloc(sizeof(p_arg) * philo.n_philo);
    if (!philo.philos)
        return 200;
    long int start_time = get_current_t();
    i = 0;
    while(i < philo.n_philo)
    {
        philo.philos[i].id = i + 1;
        philo.philos[i].start_time = start_time;
        philo.philos[i].last_meal = start_time;
        philo.philos[i].left_f = &philo.fork[i];
        philo.philos[i].right_f = &philo.fork[(i + 1) % philo.n_philo];
        philo.philos[i].data = &philo;
        i++;
    }
    philo.threads = malloc(sizeof(pthread_t) * philo.n_philo);
    if (!philo.threads)
        return 200;
    i = 0;
    while(i < philo.n_philo)
    {
        pthread_create(&philo.threads[i], NULL, &routine, &philo.philos[i]);
        usleep(10);
        i++;
    }
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
    i = 0;
    while(i < philo.n_philo)
    {
        pthread_join(philo.threads[i], NULL);
        i++;
    }
    return (0);
}
