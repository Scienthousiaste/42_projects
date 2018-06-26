# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 14:23:34 by tbehra            #+#    #+#              #
#    Updated: 2018/05/24 19:19:26 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= tbehra.filler 

SRCDIR	= src
OBJDIR	= obj
INCDIR	= include

SRC		= filler.c parsing.c tactic.c frontier.c fill_frontier.c			\
			update_test_frontier.c write.c parse_tab.c check_contact.c		\
			fill_test_frontier.c

OBJ		= $(SRC:.c=.o)

LIBFTPRINTF	= ft_printf/libftprintf.a
LIBFT		= ft_printf/libft/libft.a

OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

all: printfcomp $(OBJDIR) $(NAME)

re: fclean all

printfcomp:
	make all -C ft_printf/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	make clean -C ft_printf/
	rm -rf $(OBJDIR)

fclean:
	make fclean -C ft_printf/
	rm -rf $(OBJDIR)
	rm -f $(NAME)

$(NAME): $(OBJP)
	$(CC) $(CFLAGS) -o $@ $^ $(INCP) $(LIBFTPRINTF) $(LIBFT)
