.PHONY: all re clean fclean

CPP		= clang++
FLAGS	= -std=c++98 -Wall -Werror -Wextra
CURSE	= -lncurses
NAME	= ft_gkrellm

SRCDIR	= src
INCDIR	= include
OBJDIR	= obj

SRC		=	main.cpp				\
			AModule.cpp				\
			HostnameModule.cpp		\
			TimeModule.cpp			\
			ADisplay.cpp			\
			TerminalDisplay.cpp		\
			OsInfosModule.cpp		\
			CpuModule.cpp			\
			MemoryModule.cpp		\
			NetworkModule.cpp		\
			DiskModule.cpp			\
			GraphicalDisplay.cpp	\
			utils.cpp



HEAD	= 	ft_gkrellm.hpp			\
			defines.hpp				\
			AModule.hpp				\
			HostnameModule.hpp		\
			TimeModule.hpp			\
			ADisplay.hpp			\
			TerminalDisplay.hpp		\
			OsInfosModule.hpp		\
			CpuModule.hpp			\
			MemoryModule.hpp		\
			NetworkModule.hpp		\
			DiskModule.hpp			\
			GraphicalDisplay.hpp	\

SFML	= -I ~/.brew/include
SFMLLINK	= -L ~/.brew/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio -rpath ~/.brew/lib

OBJ		= $(SRC:.cpp=.o)

HEADP	= $(addprefix $(INCDIR)/, $(HEAD))
OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(foreach dir, $(INCDIR), -I$(dir))

all: $(OBJDIR) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADP)
	$(CPP) $(FLAGS) -c -o $@ $< $(INCP) $(SFML)

$(OBJDIR):
	mkdir -p $(OBJDIR)

re: fclean all

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

$(NAME): $(OBJP)
	$(CPP) $(FLAGS) $(CURSE) -o $@ $^ $(INCP) $(SFMLLINK)
