/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:35:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/14 18:20:05 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
# include <limits.h>
#include <stdlib.h>

typedef struct ncom_arg p_arg;

typedef struct common_arg
{
    int n_philo;
    int trip_philo;
    int teat_philo;
    int tsleep_philo;
    int neat_philo;
    p_arg *philos;
    pthread_t *threads;
    
}			c_arg;
typedef struct ncom_arg
{
    int id;
    int start_time;
}			p_arg;

long long	ft_atoi_up(char *str);
char	*ft_strtrim(char *s1, char *set);
int ft_strlen(char *s);
int from_av_to_philo(c_arg *philo, int ac, char **av);

#endif