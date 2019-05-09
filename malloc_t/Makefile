# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 11:38:21 by tbehra            #+#    #+#              #
#    Updated: 2019/05/07 11:14:25 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address
NAME	= libft_malloc.so 

SRCDIR	= src
OBJDIR	= obj
INCDIR	= include
LIBDIR	= $(INCDIR)/libftprintf

SRC		= malloc.c free.c init.c tests.c utils.c malloc_large.c new_mmap.c \
		  zone.c

HEAD	= malloc.h ft_printf.h get_next_line.h libft.h

LIBFTPRINTF = $(LIBDIR)/libftprintf.a
LIBFT	 = $(LIBDIR)/libft/libft.a

OBJ		= $(SRC:.c=.o)

HEADP	= $(addprefix $(INCDIR)/, $(HEAD))
OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

all: $(LIBFTPRINTF) $(OBJDIR) test

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCP)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	make all -C $(LIBDIR)/libft

$(LIBFTPRINTF): $(LIBFT)
	make all -C $(LIBDIR)

malloc_lib:
	ar rc $(NAME) $(OBJP)

test: $(OBJP)
	$(CC) $(CFLAGS) $^ $(INCP) $(LIBFTPRINTF) $(LIBFT)

clean:
	make clean -C $(LIBDIR)
	rm -rf $(OBJDIR)

fclean:
	make fclean -C $(LIBDIR)
	rm -rf $(OBJDIR)
	rm -f $(NAME)

$(NAME): $(OBJP) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(INCP) $(LIBFTPRINTF) $(LIBFT)
