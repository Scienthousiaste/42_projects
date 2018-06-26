# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 16:14:56 by tbehra            #+#    #+#              #
#    Updated: 2018/05/31 18:06:21 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
CHECKER	= checker
NAME	= push_swap

SRCDIR	= src
OBJDIR	= obj
INCDIR	= include

SRC_CHK	= checker.c ps_stack.c ps_stack_io.c swap.c push.c rotate.c 		\
		  rev_rotate.c display.c instructions.c
SRC		= push_swap.c ps_stack.c ps_stack_io.c instructions.c swap.c push.c \
		 rotate.c rev_rotate.c display.c 

OBJ_CHK	= $(SRC_CHK:.c=.o)
OBJ		= $(SRC:.c=.o)

LIBFT	= -Llibft/ -lft

OBJCHKP	= $(addprefix $(OBJDIR)/, $(OBJ_CHK))
OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

all: libftcomp $(OBJDIR) $(CHECKER) $(NAME)

re: fclean all

libftcomp:
	make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	make clean -C libft/
	rm -rf $(OBJDIR)

fclean:
	make fclean -C libft/
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	rm -f $(CHECKER)

$(NAME): $(OBJP)
	$(CC) $(CFLAGS) -o $@ $^ $(INCP) $(LIBFT)

$(CHECKER): $(OBJCHKP)
	$(CC) $(CFLAGS) -o $@ $^ $(INCP) $(LIBFT)
