/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocat_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:34:20 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/16 10:05:02 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocat(t_arg *philo)
{
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->n_philo);
	if (!philo->fork)
		return (300);
	philo->philos = malloc(sizeof(t_s_arg) * philo->n_philo);
	if (!philo->philos)
		return (200);
	philo->threads = malloc(sizeof(pthread_t) * philo->n_philo);
	if (!philo->threads)
		return (200);
	return (0);
}
