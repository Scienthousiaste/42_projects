# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/21 13:52:07 by tbehra            #+#    #+#              #
#    Updated: 2018/06/24 13:35:43 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= fdf 

SRCDIR	= src
OBJDIR	= obj
INCDIR	= include

SRC		= mlx.c parsing.c main.c bresenham.c projection.c images.c	\
		  display.c

HEAD	= fdf.h display.h

OBJ		= $(SRC:.c=.o)

LIBFT	= ft_printf/libft/libft.a
PRINTF	= ft_printf/libftprintf.a

HEADP	= $(addprefix $(INCDIR)/, $(HEAD))
OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

MLXP	= -I/usr/local/include
MLX		= -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(LIBFT) $(OBJDIR) $(NAME)

re: fclean all

$(PRINTF):
	make all -C ft_printf/

$(LIBFT):
	make all -C ft_printf/libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADP) $(PRINTF)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT) -I$(PRINTF) $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	make clean -C ft_printf/
	rm -rf $(OBJDIR)

fclean:
	make fclean -C ft_printf/
	rm -rf $(OBJDIR)
	rm -f $(NAME)

$(NAME): $(LIBFT) $(OBJP) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -I$(LIBFT) -I$(PRINTF) $(MLXP) $(MLX)
