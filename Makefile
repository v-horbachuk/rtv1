#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhorbach <vhorbach@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 13:58:22 by vhorbach          #+#    #+#              #
#    Updated: 2018/11/28 18:55:15 by vhorbach         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RTv1

SRC = ./src/main.c \
	  ./src/sphere.c \
	  ./src/vectors_1.c \
	  ./src/vectors_2.c \
	  ./src/plane.c \
	  ./src/cylinder.c \
	  ./src/cone.c \
	  ./src/scene.c \
	  ./src/shadows.c \
	  ./src/draw.c \
	  ./src/keycodes.c \
	  ./src/scene_t_compare.c \
	  ./src/scene_params.c \
	  ./src/matrix.c \
	  ./src/change_units.c \
	  ./src/primitive_params.c \

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

INCL = -I ./includes/ \
		-I ./libft

all: $(NAME)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(OBJ) -L./libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

./libft/libft.a:
	make -C ./libft

%.o: %.c
	gcc $(FLAG) $(INCL) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all
