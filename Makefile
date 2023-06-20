# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 17:44:58 by emohamed          #+#    #+#              #
#    Updated: 2023/06/20 12:11:15 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g
NAME = philo
SRCS = atoi_up.c from_av_to_philo.c main.c philo_need.c usleep.c protect_message.c full_struct.c is_death.c\
	 allocat_philo.c init_philo.c thread_routine.c check_all_eat.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@


all : $(NAME)


$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

