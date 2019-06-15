
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 11:43:17 by tbehra            #+#    #+#              #
#    Updated: 2019/05/20 15:51:12 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CPP		= clang++
FLAGS	= -Wall -Werror -Wextra
NAME	= eval_expr 

SRCDIR	= src
INCDIR	= include
OBJDIR	= obj

SRC		= eval_expr.cpp Fixed.cpp 

HEAD	= eval_expr.hpp Fixed.hpp 

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
