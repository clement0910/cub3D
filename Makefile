
C = gcc

NAME = Cub3D

SRCS =	srcs/cub_main.c \
		srcs/cub_image.c \
		srcs/cub_other.c \
		srcs/cub_hook_key.c \
		srcs/cub_hook_button.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		srcs/cub_parse.c \
		srcs/cub_parse_fill.c \
		srcs/cub_parse_func.c \
		srcs/cub_debug.c \
		srcs/cub_raycast.c \
		srcs/cub_raycast_player.c \
		srcs/cub_init.c \
		srcs/cub_menu.c \
		srcs/cub_quit.c \
		srcs/cub_sprite.c \
		srcs/cub_print_sprite.c \
		srcs/cub_print_floor.c \
		srcs/cub_parse_map.c \
		srcs/cub_init_ray.c \
		srcs/cub_parse_maputils.c \
		srcs/cub_parse_spriteinfo.c \
		srcs/cub_parse_spriteutils.c \


HEADER = -I libft/ -I minilibx/ -I includes/ 

FLAGS =  -Werror -Wall -Wextra -O3 

MLX = minilibx/libmlx.dylib

FW = -L minilibx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a


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

