# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 15:49:52 by tbehra            #+#    #+#              #
#    Updated: 2019/05/29 20:16:17 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all re clean fclean

FLAGS	= -pedantic -std=c++98 -Wall -Werror -Wextra
NAME	= testIter 

SRC		= iter.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

re: fclean all

clean:
	@echo "nothing to clean"

fclean:
	rm -f $(NAME)
