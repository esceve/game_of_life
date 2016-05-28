##
## Makefile for SDL_Context in /home/guerin_q/SDL_Context
## 
## Made by Quentin Guerin
## Login   <guerin_q@epitech.net>
## 
## Started on  Sat May 28 10:20:51 2016 Quentin Guerin
## Last update Sat May 28 18:10:27 2016 Quentin Guerin
##

AR			= ar

CC			= gcc

DEBUG			= 0

RM			= rm -rf

ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -D_DEBUG
endif

CFLAGS			+= -W -Wall -Wextra
CFLAGS			+= -I./includes/

ARFLAGS			+=  -rcs

NAME			= ../libsdl_context.a

SRCS			= ./srcs/init.c			\
			  ./srcs/release.c		\
			  ./srcs/set_map_size.c		\
			  ./srcs/windowevent.c		\

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(AR) rcs -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
