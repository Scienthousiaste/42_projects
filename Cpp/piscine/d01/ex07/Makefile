# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 15:31:25 by tbehra            #+#    #+#              #
#    Updated: 2019/05/21 15:31:49 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CPP		= g++
FLAGS	= -Wall -Werror -Wextra
NAME	= replace 

SRCDIR	= src
INCDIR	= include
OBJDIR	= obj

SRC		= replace.cpp 

HEAD	= replace.hpp

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
