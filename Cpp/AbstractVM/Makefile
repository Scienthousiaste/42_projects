# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/15 14:34:48 by tbehra            #+#    #+#              #
#    Updated: 2019/06/17 17:18:49 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CPP		= clang++
FLAGS	= -std=c++11 -Wall -Werror -Wextra
NAME	= AbstractVM 

SRCDIR	= src
INCDIR	= include
OBJDIR	= obj

SRC		= main.cpp Factory.cpp Exceptions.cpp AbstractVM.cpp Parser.cpp

HEAD	= defines.h Factory.hpp IOperand.hpp Operand.hpp Exceptions.hpp IterStack.hpp AbstractVM.hpp Parser.hpp

OBJ		= $(SRC:.cpp=.o)

HEADP	= $(addprefix $(INCDIR)/, $(HEAD))
OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

all: $(OBJDIR) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADP)
	$(CPP) $(FLAGS) -c -o $@ $< $(INCP)

$(OBJDIR):
	mkdir -p $(OBJDIR)

re: fclean all

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

$(NAME): $(OBJP)
	$(CPP) $(FLAGS) -o $@ $^ $(INCP)
