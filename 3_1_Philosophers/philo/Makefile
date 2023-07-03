CC=	cc
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = philo

LIBFT = ./libft/libft.a
HEADER = philo.h
HEADERS = $(addprefix include/, $(HEADER))

SRC = philo.c simul.c philo_eating.c util.c
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.c=.o)

.PHONY: clean, fclean, re, all

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -Llibft -lft -Iinclude -o $@ $(OBJS);

$(LIBFT): ./include/libft.h
	$(MAKE) -C ./libft all

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Iinclude -o $@ -c $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all
