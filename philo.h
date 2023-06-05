/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:35:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/05 14:52:01 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int err(void);

typedef struct s_arg
{
    int n_philo;
    int trip_philo;
    int teat_philo;
    int tsleep_philo;
    int neat_philo;
}			t_arg;
void *is_eating();
void *is_thinking();
void *is_sleeping();
void *is_dead();

#endif