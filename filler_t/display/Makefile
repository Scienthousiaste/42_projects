# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 13:08:41 by tbehra            #+#    #+#              #
#    Updated: 2018/05/28 16:08:45 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= display

SRCDIR	= src
OBJDIR	= obj
INCDIR	= include

SRC		= init_display.c deal_key.c display_scores.c first_parsing.c 		\
		  parsing.c images.c turn.c utils.c

OBJ		= $(SRC:.c=.o)

OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))
LIBFT	= ../ft_printf/libft/libft.a
LIBFTPRINTF	= ../ft_printf/libftprintf.a

MLXP	= -I/usr/local/include
MLX		= -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(OBJDIR) $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR)
	rm -f $(NAME)

$(NAME): $(OBJP) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(INCP) $(MLXP) $(MLX) -I$(LIBFT) -I$(LIBFTPRINTF)
