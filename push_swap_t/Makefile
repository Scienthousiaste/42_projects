# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 16:14:56 by tbehra            #+#    #+#              #
#    Updated: 2018/07/29 16:25:33 by tbehra           ###   ########.fr        #
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

SRC_CH	= checker.c ps_stack.c ps_stack_io.c swap.c push.c rotate.c 		\
		  rev_rotate.c display.c instructions.c utils.c ps_init.c sort.c	\

SRC_PS	= push_swap.c ps_stack.c ps_stack_io.c swap.c push.c rotate.c		\
		  rev_rotate.c display.c instructions.c utils.c ps_init.c sort.c	\

HEAD	= push_swap.h get_next_line.h libft.h t_ps_stack.h

OBJ_CH	= $(SRC_CH:.c=.o)
OBJ_PS	= $(SRC_PS:.c=.o)

LIBFT	= -Llibft/ -lft

HEADP	= $(addprefix $(INCDIR)/, $(HEAD))
OBJ_CHP	= $(addprefix $(OBJDIR)/, $(OBJ_CH))
OBJ_PSP	= $(addprefix $(OBJDIR)/, $(OBJ_PS))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

all: libftcomp $(OBJDIR) $(CHECKER) $(NAME)

re: fclean all

libftcomp:
	make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADP)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCP)

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

$(NAME): $(OBJ_PSP) $(HEADP)
	$(CC) $(CFLAGS) -o $@ $(OBJ_PSP) $(INCP) $(LIBFT)

$(CHECKER): $(OBJ_CHP) $(HEADP)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CHP) $(INCP) $(LIBFT)
