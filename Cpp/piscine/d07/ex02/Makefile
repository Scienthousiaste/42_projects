# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 20:13:55 by tbehra            #+#    #+#              #
#    Updated: 2019/05/30 13:28:49 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

FLAGS	= -pedantic -std=c++98 -Wall -Werror -Wextra
NAME	= testArray 

INC		= Array.hpp
SRC		= main.cpp

all: $(NAME)

$(NAME): $(SRC) $(INC)
	clang++ $(FLAGS) $(SRC) -o $(NAME) 

re: fclean all

clean:
	@echo "nothing to clean"

fclean:
	rm -f $(NAME)
