# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 14:02:25 by esirnio           #+#    #+#              #
#    Updated: 2023/11/26 16:33:37 by esirnio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

PHONY: all fclean clean re
