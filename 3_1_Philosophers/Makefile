CC=	cc
CFLAGS = -Wall -Wextra -Werror


.PHONY: clean, fclean, re, all, bonus

all:
	$(MAKE) -C ./philo

bonus:
	$(MAKE) -C ./philo_bonus

clean:
	$(MAKE) -C ./philo clean
	$(MAKE) -C ./philo_bonus clean

fclean: clean
	$(MAKE) -C ./philo fclean
	$(MAKE) -C ./philo_bonus fclean

re: fclean all
