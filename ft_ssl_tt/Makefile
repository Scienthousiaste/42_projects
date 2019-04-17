# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:07:23 by tbehra            #+#    #+#              #
#    Updated: 2019/04/17 13:37:07 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= ft_ssl

SRCDIR	= src
OBJDIR	= obj
INCDIR	= include

SRC		=	main.c md5.c md5_auxiliary_functions.c md5_init.c md5_loop.c 	\
			utils.c md5_build_block.c sha256.c errors.c sha256_init.c		\
			sha256_loop.c sha256_build_block.c sha256_auxiliary_functions.c \
			sha256_auxiliary_functions2.c

HEAD	= ft_ssl.h md5.h sha256.h

OBJ		= $(SRC:.c=.o)

LIBFT	= libft/libft.a

HEADP	= $(addprefix $(INCDIR)/, $(HEAD))
OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

all: $(LIBFT) $(OBJDIR) $(NAME)

re: fclean all

$(LIBFT):
	make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADP)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT) $(INCP)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make clean -C libft/
	rm -rf $(OBJDIR)

fclean:
	make fclean -C libft/
	rm -rf $(OBJDIR)
	rm -f $(NAME)

$(NAME): $(LIBFT) $(OBJP)
	$(CC) $(CFLAGS) -o $@ $^ -I$(LIBFT)

varprint:
	@echo $(OBJP)
	@echo $(HEADP)
	@echo $(SRCDIR)
	@echo $(INCP)
