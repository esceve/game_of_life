##
## Makefile for Generic Makefile in /home/esceve/Documents/C/informations
## 
## Made by Clement Scherpereel
## Login esceve <clement.scherpereel@outlook.fr>
## 
## Started on  Thu May 12 23:11:11 2016 Clement Scherpereel
## Last update Sat May 28 19:11:38 2016 Clement Scherpereel
##

DEBUG			= 0

CC			= gcc

RM			= rm -f

CFLAGS			+= -W -Wall -Wextra
CFLAGS			+= -I./includes/

ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -D _DEBUG
endif

LDFLAGS			+= -L./libraries/ -lSDL2 -lsdl_context

NAME			=game_of_life.x86_64

SRCS			= ./srcs/main.c					\
			  ./srcs/create_map.c				\
			  ./srcs/display_map.c				\
			  ./srcs/test_cells.c				\

OBJS			= $(SRCS:.c=.o)

all:			library $(NAME)

library:
			make -C ./libraries/SDL_Context/

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
			$(RM) $(OBJS)
			make clean -C ./libraries/SDL_Context/

fclean:
			$(RM) $(OBJS)
			$(RM) $(NAME)
			make fclean -C ./libraries/SDL_Context/

re:			fclean all

.PHONY:			all library clean fclean re
