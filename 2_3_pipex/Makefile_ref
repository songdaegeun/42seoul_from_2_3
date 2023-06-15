CC=	cc
CFLAGS=	-Wall -Wextra -Werror

NAME = fdf
BONUS_NAME = fdf_bonus

SPRINTF = ./ft_sprintf/libftsprintf.a
SPRINTF_HEADERDIR = ./ft_sprintf/includes
SPRINTF_HEADER = libft.h ft_sprintf.h ft_res_print.h ft_str_process.h ft_convert_base2nbr.h ft_convert_num.h ft_res_s.h ft_printf_syntax.h ft_convert_util.h ft_convert_util_2.h
SPRINTF_HEADERS = $(addprefix $(SPRINTF_HEADERDIR)/, $(SPRINTF_HEADER))

HEADERS = fdf.h get_next_line.h libft.h $(SPRINTF_HEADERS)
SRCS = fdf.c get_next_line_utils.c get_next_line.c graphic.c graphic2.c graphic3.c mlx_custom.c parse_map.c callback.c util.c color.c option.c projection.c preset.c put_ctl_msg.c
OBJS = $(SRCS:.c=.o)

BONUS_HEADERS = fdf_bonus.h get_next_line.h libft.h $(SPRINTF_HEADERS)
BONUS_SRCS = fdf_bonus.c get_next_line_utils.c get_next_line.c graphic_bonus.c graphic2_bonus.c graphic3_bonus.c mlx_custom_bonus.c parse_map_bonus.c callback_bonus.c util_bonus.c color_bonus.c option_bonus.c projection_bonus.c preset_bonus.c put_ctl_msg_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o) 

.PHONY: clean, fclean, re, all, bonus

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(SPRINTF)
	$(CC) $(CFLAGS) -L./mlx -L./ft_sprintf -lmlx -lftsprintf -lm -framework OpenGL -framework AppKit -o $@ $(OBJS);\
	install_name_tool -change libmlx.dylib @executable_path/mlx/libmlx.dylib $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(SPRINTF)
	$(CC) $(CFLAGS) -L./mlx -L./ft_sprintf -lmlx -lftsprintf -lm -framework OpenGL -framework AppKit -o $@ $(BONUS_OBJS);\
	install_name_tool -change libmlx.dylib @executable_path/mlx/libmlx.dylib $(BONUS_NAME)

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(SPRINTF): $(SPRINTF_HEADERS)
	$(MAKE) -C ./ft_sprintf;

clean:
	rm -f $(OBJS);\
	rm -f $(BONUS_OBJS);\
	$(MAKE) -C ./ft_sprintf clean;

fclean: clean
	rm -f $(NAME);\
	rm -f $(BONUS_NAME);\
	$(MAKE) -C ./ft_sprintf fclean

re: fclean all
