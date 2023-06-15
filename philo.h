/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:35:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/15 19:48:40 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct ncom_arg	p_arg;

typedef struct common_arg
{
	int					n_philo;
	int					trip_philo;
	int					teat_philo;
	int					tsleep_philo;
	int					neat_philo;
	p_arg				*philos;
	pthread_t			*threads;
	pthread_mutex_t		*fork;
	pthread_mutex_t		protect_print;

}						c_arg;
typedef struct ncom_arg
{
	int					id;
	long int			start_time;
	pthread_mutex_t		*right_f;
	pthread_mutex_t		*left_f;
	long int			last_meal;
	c_arg				*data;
}						p_arg;

long long				ft_atoi_up(char *str);
char					*ft_strtrim(char *s1, char *set);
int						ft_strlen(char *s);
int						from_av_to_philo(c_arg *philo, int ac, char **av);
long int				get_current_t(void);
void					sleeping(int n);
void					print_protect(p_arg *philo, char *msg);
void					full_philo(c_arg philo);
void					*routine(void *p);
void					full_thread(c_arg philo);
void					full_mutex(c_arg philo);
int						is_death(c_arg philo);
void					full_thread_join(c_arg philo);
int						allocat(c_arg *philo);

#endif