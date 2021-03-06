# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 18:21:10 by tbehra            #+#    #+#              #
#    Updated: 2018/07/24 15:40:53 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= fractol 

SRCDIR	= src
OBJDIR	= obj
INCDIR	= include

SRC		= main.c complex.c mandelbrot.c mlx.c display.c images.c colors.c \
		  display_utils.c julia.c complex_fractals.c collatz.c buddhabrot.c \
		  burning_ship.c check_params.c complex_angles.c complex_op.c

HEAD	= fractol.h libft.h display.h

OBJ		= $(SRC:.c=.o)

LIBFT	= libft/libft.a

HEADP	= $(addprefix $(INCDIR)/, $(HEAD))
OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

MLXP	= -I/usr/local/include
MLX		= -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(LIBFT) $(OBJDIR) $(NAME)

re: fclean all

$(LIBFT):
	make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADP)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT) $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	make clean -C libft/
	rm -rf $(OBJDIR)

fclean:
	make fclean -C libft/ 
	rm -rf $(OBJDIR)
	rm -f $(NAME)

$(NAME): $(LIBFT) $(OBJP)
	$(CC) $(CFLAGS) -o $@ $^ -I$(LIBFT) $(MLXP) $(MLX)
