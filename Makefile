# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skillian <skillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:48:02 by skillian          #+#    #+#              #
#    Updated: 2021/11/29 18:33:01 by skillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Wextra -Werror -L ./mlx -lmlx -framework OpenGL -framework AppKit

MLX = 	mlx/libmlx.a
LIBFT = Libft/libft.a
SRC = 	so_long.c \
		window.c \
		images.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c\
		interpret_mapfield_and_print.c\
		read_map_lines.c\
		read_xy_map.c\
		key_input.c\
		errors.c\
		freen.c

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -D BUFFER_SIZE=100 $^ -o $@
	
$(NAME): $(MLX) $(LIBFT) $(OBJ)
	gcc $(FLAGS) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

$(MLX):
	make --directory=./mlx

$(LIBFT):
	make --directory=./Libft

clean:
	rm -fr $(OBJ)

fclean:
	make clean
	rm -fr $(NAME)

re: fclean all
