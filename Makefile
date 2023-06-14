CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = philo

SRCS = *.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@


all : $(NAME)


$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $^  -o $@ 

clean:
	make -C libft/ clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

