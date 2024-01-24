# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:49:03 by esirnio           #+#    #+#              #
#    Updated: 2023/12/08 13:39:06 by esirnio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp\
		Materiasource.cpp Trash.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

PHONY: all fclean clean re