# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 11:43:17 by tbehra            #+#    #+#              #
#    Updated: 2019/05/20 13:47:43 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CPP		= g++
FLAGS	= -Wall -Werror -Wextra
NAME	= megaphone 

SRC		= megaphone.cpp 

all: $(NAME) 

re: fclean all

clean:
	@echo "Nothing to clean"

fclean: 
	rm -f $(NAME)

$(NAME): $(SRC)
	$(CPP) $(FLAGS) -o $@ $^
