/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:36:02 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/05 14:55:30 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// int main(int ac, char **av)
// {
//     if (ac < 4 || ac > 5)
//         err();

// }

int main()
{
    pthread_t t1;   
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;


    pthread_create(&t1, NULL, is_eating, NULL);
    pthread_create(&t2, NULL, is_thinking, NULL);
    pthread_create(&t3, NULL, is_sleeping, NULL);
    pthread_create(&t4, NULL, is_dead, NULL);
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t2, NULL);
    
}