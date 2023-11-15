# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabel <aabel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/11/15 12:18:05 by aabel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = Cube3D
SOURCES = src/main/main.c src/main/ft_check_up_down.c src/main/ft_draw.c src/main/ft_texture.c \
		src/Parsing/ft_parsing.c src/Parsing/ft_parsing_texture.c src/Parsing/ft_parsing_map.c src/Parsing/ft_return_error.c src/Parsing/ft_check_texture.c src/Parsing/ft_check_colors.c\
		src/move_hitbox/hitbox.c src/move_hitbox/move.c src/move_hitbox/rotate.c src/move_hitbox/player_start.c src/main/init_door.c \
			
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = inc/libft/libft.a
INC_DIR = inc/
MLX42 = ../Cube3D/MLX42/build/libmlx42.a
# MLXSRC = -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
MLXSRC = -Iinclude -lglfw -L"/Users/aabel/.brew/opt/glfw/lib/"

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
