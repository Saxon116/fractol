# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 12:50:22 by nkellum           #+#    #+#              #
#    Updated: 2019/09/04 16:02:54 by nkellum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = src/main.c src/mandelbrot.c src/julia.c src/zoom.c src/burning_ship.c \
src/tricorn.c src/draw.c src/mouse.c src/key.c src/init.c
OBJ = $(SRC:.c=.o)

# This is a minimal set of ANSI/VT100 color codes
_END=\x1b[0m
_BOLD=\x1b[1m
_UNDER=\x1b[4m
_REV=\x1b[7m

# Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m


all: $(NAME)

$(NAME): $(SRC)
	@ make -C libft
	@ make -C minilibx_macos
	@cc -o $(NAME) -I /usr/local/include $(SRC) -L ./minilibx_macos -lmlx \
	-lm -framework OpenGL -framework AppKit libft/libft.a
	@echo "${_GREEN}Compiled fractol${_END}"

linux: $(SRC)
	@ make -C libft
	@gcc -o $(NAME) $(SRC) libft/libft.a -L./minilibx_linux -lmlx \
	-lm -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	@echo "\e[36mCompiled fdf for Linux\e[0m"

%.o: %.c libft.h
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C minilibx_macos clean

re: fclean all
