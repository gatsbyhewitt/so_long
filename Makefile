# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 18:26:11 by abestaev          #+#    #+#              #
#    Updated: 2022/02/08 18:26:13 by abestaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

NAME = so_long

SRC = src/utils.c src/key_hook.c src/move.c src/move_utils.c \
		so_long.c src/draw_map.c src/check_map.c src/error.c src/init.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c

HEADER = -I includes -I libft -I minilibX

LIBFT = -L libft -lft

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME):
		make -C libft/
		make -C minilibX/
		$(CC) $(CFLAGS) -o $(NAME) $(HEADER) $(SRC) -g -L minilibX/ $(LIBFT) -lmlx -lXext -lX11

r: re
		./$(NAME) map/map1.ber

clean:
		make clean -C libft
		make clean -C minilibX
		rm -rf $(OBJ)

fclean: clean
		make fclean -C libft
		rm -rf $(NAME)

re: fclean all