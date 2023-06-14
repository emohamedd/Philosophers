/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:36:02 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/14 17:49:07 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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
}
