CC=	cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo
BONUS_NAME = philo_bonus

# LIBFT = ./libft/libft.a
HEADER = philo.h
HEADERS = $(addprefix include/, $(HEADER))

SRC = philo.c
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.c=.o)

# BONUS_HEADERS = pipex_bonus.h
# BONUS_SRCS = pipex_bonus.c pipe_read_end_bonus.c pipe_write_end_bonus.c pipe_middle_bonus.c heredoc_bonus.c
# BONUS_OBJS = $(BONUS_SRCS:.c=.o) 

.PHONY: clean, fclean, re, all, bonus

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iinclude -o $@ $(OBJS);
# -Iphilo/include

# $(BONUS_NAME): $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) -Llibft -lft -o $@ $(BONUS_OBJS);\

# $(LIBFT): libft.h
# 	$(MAKE) -C ./libft all

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

# $(BONUS_OBJS): %.o: %.c $(BONUS_HEADERS)
# 	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all
