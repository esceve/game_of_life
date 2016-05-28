/*
** release.c for SDL_Context in /home/guerin_q/rendu/game_of_life/libraries/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 15:12:05 2016 Quentin Guerin
** Last update Sat May 28 15:22:18 2016 Quentin Guerin
*/

#include	"SDLContext.h"

void		SDLContext_release(void **context)
{
  SDL_DestroyWindow(((struct SDLContext*)(*context))->window);
  SDL_DestroyRenderer(((struct SDLContext*)(*context))->renderer);
  *context = NULL;
}
