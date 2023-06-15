/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_av_to_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:13:30 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/15 19:43:25 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	from_av_to_philo(c_arg *philo, int ac, char **av)
{
	if ((ft_atoi_up(av[0]) == 0 || ft_atoi_up(av[1]) == 0
			|| ft_atoi_up(av[2]) == 0 || ft_atoi_up(av[3]) == 0))
	{
		printf("Error\n");
		return (0);
	}
	philo->n_philo = ft_atoi_up(av[0]);
	philo->trip_philo = ft_atoi_up(av[1]);
	philo->teat_philo = ft_atoi_up(av[2]);
	philo->tsleep_philo = ft_atoi_up(av[3]);
	if (ac == 6)
	{
		if (ft_atoi_up(av[4]) == 0)
		{
			printf("Error\n");
			return (0);
		}
		else
			philo->neat_philo = ft_atoi_up(av[4]);
	}
	else
		philo->neat_philo = -1;
	return (1);
}
