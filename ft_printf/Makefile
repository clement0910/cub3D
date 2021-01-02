
C = gcc

NAME = libftprintf.a

SRCS = srcs/ft_printf.c \
		srcs/ft_printf_flags.c \
		srcs/ft_printf_aux.c \
		srcs/ft_printf_conversion.c \
		srcs/ft_printf_conversion2.c \
		srcs/ft_printf_conversion_bonus.c \
		srcs/ft_printf_convertutils.c \
		srcs/ft_printf_convertutils_bonus.c \
		srcs/ft_printf_flags_bonus.c \
		srcs/ft_printf_aux_bonus.c \
		srcs/ft_printf_conversiond_bonus.c \
		srcs/ft_printf_conversionu_bonus.c \
		srcs/ft_printf_conversionx_bonus.c \
		srcs/ft_printf_conversionxmaj_bonus.c \

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

LIB = ../libft/libft.a

all: $(NAME)

$(LIB):
	make bonus -C ../libft/

$(NAME): $(LIB) $(OBJ)
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) $(LIB)

%.o: %.c includes/libftprintf.h
	$(CC) -I includes/ -o $@ -c $< $(FLAGS)

bonus: all

clean:
	rm -rf $(OBJ)
	make clean -C ../libft/

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB)

re: fclean all