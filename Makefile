NAME	= ft_gkrellm
CC		= clang++
NCURSES	= -lncurses
SFML	= -L/Users/pguillie/.brew/Cellar/sfml/2.4.2_1/lib -lsfml-graphics -lsfml-window -lsfml-system
WFLAGS	= -Wall -Werror -Wextra
FLAG98	= -std=c++98
FLAGS	= $(WFLAGS) $(FLAG98)

INC		= -I includes -I /Users/pguillie/.brew/Cellar/sfml/2.4.2_1/include

HEADERS	= $(addprefix includes/, \
			CPU.class.hpp \
			Disk.class.hpp \
			IMonitorDisplay.class.hpp \
			MonitorGraphical.class.hpp \
			MonitorShell.class.hpp \
			IMonitorModule.class.hpp \
			Name.class.hpp \
			Network.class.hpp \
			OS.class.hpp \
			RAM.class.hpp \
			Time.class.hpp \
			)

SOURCES	= $(addprefix src/, \
			CPU.class.cpp \
			Disk.class.cpp \
			MonitorShell.class.cpp \
			MonitorGraphical.class.cpp \
			Name.class.cpp \
			Network.class.cpp \
			OS.class.cpp \
			RAM.class.cpp \
			Time.class.cpp \
			ft_gkrellmExceptions.cpp \
			initMonitorDisplay.cpp \
			main.cpp \
			)

OBJECTS	= $(SOURCES:src/%.cpp=obj/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): obj $(OBJECTS)
	$(CC) $(FLAGS) $(NCURSES) $(SFML) -o $@ $(OBJECTS)

obj/%.o: src/%.cpp $(HEADERS) Makefile
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

obj:
	mkdir -p ./obj

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all
