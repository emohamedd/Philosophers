/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:47:40 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/05 14:55:22 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *is_eating()
{
    while(1)
    {
        printf("45 55 is eating\n");
        sleep(1);
    }
        return NULL;   
    
}
void *is_thinking()
{
     while(1)
    {
         printf("151 5646 is thinking\n"); 
        sleep(1);

    }
    return NULL;
}
void *is_sleeping()
{
     while(1)
    {
        printf("11 1644 is sleeping\n"); 
        sleep(1);

    }
    return NULL;
}
void *is_dead()
{
     while(1)
    {
        printf("15616 160 is dead\n"); 
        sleep(1);

    }
    return NULL;
}