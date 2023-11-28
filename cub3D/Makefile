# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 14:36:25 by dcandan           #+#    #+#              #
#    Updated: 2023/11/27 17:05:13 by dcandan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SOURCES = src/main/main.c src/main/ft_check_up_down.c src/main/ft_draw.c src/main/ft_texture.c src/Parsing/ft_impossible.c src/main/ft_free_all.c src/main/ft_free_all_utils.c \
		src/Parsing/ft_parsing.c src/Parsing/ft_parsing_texture.c src/Parsing/ft_parsing_map.c src/Parsing/ft_parsing_map_utils.c src/Parsing/ft_return_error.c src/Parsing/ft_check_texture.c src/Parsing/ft_check_colors.c\
		src/move_hitbox/hitbox.c src/move_hitbox/move.c src/move_hitbox/rotate.c src/move_hitbox/player_start.c src/main/init_door.c src/main/minimap.c src/main/minimap_utils.c src/main/ft_utils.c \
			
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
LIBFT_LIB = inc/libft/libft.a
INC_DIR = inc/
MLX42 = ../cub3D/MLX42/build/libmlx42.a
#MLXSRC = -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
MLXSRC = -Iinclude -lglfw -L"/Users/$USER/.brew/opt/glfw/lib/"
MLXFLAG = -framework Cocoa -framework OpenGL -framework IOKit 

all: ${NAME}

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I $(INC_DIR)

${NAME}: ${OBJECTS}
	make -C inc/libft
	$(CC) $(CFLAGS) -o ${NAME} ${OBJECTS} $(MLX42) $(MLXSRC) ${LIBFT_LIB} -lm

clean:
	make -C inc/libft clean
	rm -f ${OBJECTS}
	
fclean: clean
	make -C inc/libft fclean
	rm -f ${NAME}

re: fclean all
