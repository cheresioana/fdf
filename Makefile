# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/18 10:05:52 by jfazakas          #+#    #+#              #
#    Updated: 2016/12/28 15:57:47 by icheres          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c */*.c
OBJ = *.o
INC = includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L ./includes/ -lmlx -framework OpenGL -framework AppKit
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
