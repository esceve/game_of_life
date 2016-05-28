/*
** set_map_size.c for SDL_Context in /home/guerin_q/rendu/game_of_life/libraries/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 11:48:19 2016 Quentin Guerin
** Last update Sat May 28 11:49:32 2016 Quentin Guerin
*/

#include	"SDLContext.h"

void		set_map_size(void *context, int x, int y)
{
  ((struct SDLContext*)context)->x = x;
  ((struct SDLContext*)context)->y = y;
}
