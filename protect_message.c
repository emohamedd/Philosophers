/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:00:16 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/17 17:42:41 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_protect(t_s_arg *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->protect_print);
	if (*philo->rip == 0)
	{
		printf("%lld %d %s", get_current_t() - philo->start_time, philo->id,
			msg);
	}
	pthread_mutex_unlock(&philo->data->protect_print);
}
