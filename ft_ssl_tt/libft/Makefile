# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 14:33:20 by tbehra            #+#    #+#              #
#    Updated: 2018/06/29 12:13:07 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS 	= -Wall -Werror -Wextra
NAME	= libft.a

SRCDIR  = .
OBJDIR  = obj

SRC		= 	ft_lstiter.c ft_putendl.c ft_strequ.c ft_strnstr.c ft_lstmap.c 	\
			ft_putendl_fd.c ft_striter.c ft_strrchr.c ft_atoi.c ft_lstnew.c \
			ft_putnbr.c ft_striteri.c ft_strsplit.c ft_bzero.c ft_memalloc.c\
		   	ft_putnbr_fd.c ft_strjoin.c ft_strstr.c ft_isalnum.c			\
			ft_memccpy.c ft_putstr.c ft_strlcat.c ft_strsub.c ft_isalpha.c	\
			ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_strtrim.c ft_isascii.c\
			ft_memcmp.c ft_strcat.c ft_strmap.c ft_tolower.c ft_isdigit.c	\
			ft_memcpy.c ft_strchr.c ft_strmapi.c ft_toupper.c ft_isprint.c	\
			ft_memdel.c ft_strclr.c ft_strncat.c ft_itoa.c ft_utoa.c		\
			ft_ltoa.c ft_lltoa.c ft_imaxtoa.c ft_ultoa.c ft_umaxtoa.c		\
			ft_memmove.c ft_strcmp.c ft_strncmp.c ft_lstadd.c ft_memset.c	\
			ft_strcpy.c ft_strncpy.c ft_lstdel.c ft_putchar.c ft_strdel.c	\
			ft_strnequ.c ft_lstdelone.c ft_putchar_fd.c ft_strdup.c			\
			ft_strnew.c ft_lstrev.c ft_lstsize.c ft_lstpush.c ft_lstcont.c	\
			ft_lstprint.c ft_iswhitespace.c ft_itoa_base.c ft_utoa_base.c	\
			ft_ultoa_base.c ft_ltoa_base.c ft_lltoa_base.c ft_umaxtoa_base.c\
		   	ft_strtolower.c get_next_line.c ft_tabdel.c ft_index.c

INC		=	get_next_line.h libft.h

OBJ 	= $(SRC:.c=.o) 
OBJP    = $(addprefix $(OBJDIR)/,$(OBJ))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJP)
	ar rc $(NAME) $(OBJP) 

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -rf $(OBJDIR) 

$(OBJDIR):
	mkdir -p $(OBJDIR)

fclean: 
	make clean
	/bin/rm -f $(NAME)

re:
	make fclean
	make all
