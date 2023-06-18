/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:35:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/18 16:23:50 by emohamed         ###   ########.fr       */
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

typedef struct s_ncom_arg	t_s_arg;

typedef struct s_common_arg
{
	int						n_philo;
	int						trip_philo;
	int						neat_philo;
	int						tsleep_philo;
	int						teat_philo;
	t_s_arg					*philos;
	pthread_t				*threads;
	pthread_mutex_t			*fork;
	pthread_mutex_t			protect_print;
	pthread_mutex_t			protect_death;

}							t_arg;
typedef struct s_ncom_arg
{
	int						*rip;
	int						id;
	long long				start_time;
	int						cmeal;
	pthread_mutex_t			*right_f;
	pthread_mutex_t			*left_f;
	long long				last_meal;
	t_arg					*data;
}							t_s_arg;

long long					ft_atoi_up(char *str);
char						*ft_strtrim(char *s1, char *set);
int							ft_strlen(char *s);
int							from_av_to_philo(t_arg *philo, int ac, char **av);
long long					get_current_t(void);
void						sleeping(int n, t_s_arg *philo);
void						print_protect(t_s_arg *philo, char *msg);
void						full_philo(t_arg *philo, int *h);
void						*routine(void *p);
void						full_thread(t_arg *philo);
void						full_mutex(t_arg *philo);
int							is_rip(t_arg *philo, int *h);
void						full_thread_join(t_arg *philo);
int							allocat(t_arg *philo);
void						destroy_mutex(t_arg *philo);
void						full_thread_detach(t_arg *philo);
int							point_to_death(t_s_arg *philo);
void						loop_t(t_s_arg *philo);
int							time_to_die(t_arg *philo, int *h);
#endif