# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabel <aabel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 15:27:08 by dilovancand       #+#    #+#              #
#    Updated: 2023/11/09 12:30:15 by aabel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cube3D
SOURCES = src/main/main.c src/main/ft_check_up_down.c src/main/ft_draw.c \
		src/Parsing/ft_parsing.c src/Parsing/ft_parsing_texture.c src/Parsing/ft_parsing_map.c src/Parsing/ft_return_error.c src/Parsing/ft_check_texture.c src/Parsing/ft_check_colors.c\
		src/move_hitbox/hitbox.c src/move_hitbox/move.c src/move_hitbox/rotate.c \
			
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = inc/libft/libft.a
INC_DIR = inc/
MLX42 = ../Cube3D/MLX42/build/libmlx42.a
MLXSRC = -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
# MLXSRC = -Iinclude -lglfw -L"/Users/aabel/.brew/opt/glfw/lib/"

CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -framework Cocoa -framework OpenGL -framework IOKit

all: ${NAME}

%.o: %.c
	$(CC) -c $(CFLAGS) -g3 $< -o $@ -I $(INC_DIR)

${NAME}: ${OBJECTS}
	make -C inc/libft
	$(CC) $(CFLAGS) -g3 -o ${NAME} ${OBJECTS} $(MLX42) $(MLXSRC) ${LIBFT_LIB} 

clean:
	make -C inc/libft clean
	rm -f ${OBJECTS}
	
fclean: clean
	make -C inc/libft fclean
	rm -f ${NAME}

re: fclean all
