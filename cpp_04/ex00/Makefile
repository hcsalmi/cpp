# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:15:36 by lsalmi            #+#    #+#              #
#    Updated: 2024/01/22 17:15:38 by lsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphism

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(@) $(^)

%.o: %.cpp
	$(CC) $(FLAGS) -c $(<) -o $(@)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
