# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 11:43:17 by tbehra            #+#    #+#              #
#    Updated: 2019/05/26 19:47:29 by tbehra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CPP		= clang++
FLAGS	= -pedantic -std=c++98 -Wall -Werror -Wextra
CURSE	= -lncurses
NAME	= ft_retro

SRCDIR	= src
INCDIR	= include
OBJDIR	= obj

SRC		= main.cpp AEntity.cpp APhysic.cpp Asteroid.cpp Game.cpp            \
		  Spaceship.cpp Projectile.cpp BigAsteroid.cpp AGameEvent.cpp       \
		  EnemyGenerator.cpp BackgroundGenerator.cpp ABackground.cpp \
		  DistantStar.cpp AlienShip.cpp AlienWeapon.cpp Explosion.cpp Boss.cpp

HEAD	= AEntity.hpp APhysic.hpp Asteroid.hpp Game.hpp                     \
		  Spaceship.hpp Projectile.hpp BigAsteroid.hpp AGameEvent.hpp       \
		  EnemyGenerator.hpp BackgroundGenerator.hpp ABackground.hpp \
		  DistantStar.hpp const.hpp AlienShip.hpp AlienWeapon.hpp Explosion.hpp \
		  Boss.hpp

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
	$(CPP) $(FLAGS) $(CURSE) -o $@ $^ $(INCP)
