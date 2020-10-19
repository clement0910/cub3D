
C = gcc

NAME = Cub3D

SRCS =	srcs/cub_main.c \
		srcs/cub_image.c \
		srcs/cub_other.c \
		srcs/cub_hook_key.c \
		srcs/cub_hook_button.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		srcs/cub_parse_global.c \
		srcs/cub_parse_global_func.c \
		srcs/cub_debug.c \

HEADER = -I libft/ -I minilibx/ -I includes/

FLAGS =  -Wall -Wextra -O3 

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

