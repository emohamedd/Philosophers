/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:35:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/04 13:27:50 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
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

#endif