
C = gcc

NAME = Cub3D

SRCS =	srcs/cub_main.c \
		srcs/cub_image.c \
		srcs/cub_other.c \
		srcs/cub_hook_key.c \
		srcs/cub_hook_button.c \
		srcs/cub_parse.c \
		srcs/cub_parse_fill.c \
		srcs/cub_parse_func.c \
		srcs/cub_print_data.c \
		srcs/cub_raycast.c \
		srcs/cub_raycast_player.c \
		srcs/cub_init.c \
		srcs/cub_menu.c \
		srcs/cub_quit.c \
		srcs/cub_sprite.c \
		srcs/cub_print_sprite.c \
		srcs/cub_print_floor.c \
		srcs/cub_print_map.c \
		srcs/cub_print_line.c \
		srcs/cub_parse_map.c \
		srcs/cub_init_ray.c \
		srcs/cub_parse_maputils.c \
		srcs/cub_parse_spriteinfo.c \
		srcs/cub_parse_spriteutils.c \
		srcs/cub_bmp.c \
		srcs/cub_settings.c \
		srcs/cub_resume.c \
		srcs/cub_check_data.c \
		srcs/cub_events.c \
		srcs/cub_print_raycast.c \
		srcs/cub_init_xpm.c \
		srcs/cub_malloc_xpm.c \
		srcs/cub_print_error.c \


HEADER = -I libft/ -I minilibx/ -I includes/ 

FLAGS =  -Werror -Wall -Wextra -O3 

MLX = minilibx/libmlx.dylib

FW = -L minilibx -lmlx -framework OpenGL -lm -framework AppKit

LIBFT = ft_printf/libftprintf.a

OBJ = $(SRCS:.c=.o) 

%.o:%.c
	$(C) $(FLAGS) $(HEADER) -c -o $@ $<

all: $(MLX) $(NAME)

$(MLX):
	make -C minilibx/

$(NAME): $(OBJ) 
	$(C) $(FLAGS) $(LIBFT) $(FW) $(OBJ) -o $(NAME)

bonus: all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

