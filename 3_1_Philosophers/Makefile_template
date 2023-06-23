CC=	cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
BONUS_NAME = pipex_bonus

LIBFT = ./libft/libft.a
HEADERS = pipex.h
SRCS = pipex.c pipe_read_end.c pipe_write_end.c pipe_middle.c heredoc.c
OBJS = $(SRCS:.c=.o)

BONUS_HEADERS = pipex_bonus.h
BONUS_SRCS = pipex_bonus.c pipe_read_end_bonus.c pipe_write_end_bonus.c pipe_middle_bonus.c heredoc_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o) 

.PHONY: clean, fclean, re, all, bonus

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $(OBJS);\

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $(BONUS_OBJS);\

$(LIBFT): libft.h
	$(MAKE) -C ./libft all

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all
