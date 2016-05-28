/*
** setmapsize.c for SDL_Context in /home/guerin_q/rendu/game_of_life/libraries/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 11:48:19 2016 Quentin Guerin
** Last update Sat May 28 20:30:01 2016 Quentin Guerin
*/

#include		<stdio.h>
#include		"SDLContext.h"

void			SDLContext_setmapsize(void *context_ptr, int x, int y)
{
  struct SDLContext	*context;

  context = context_ptr;
  context->x = x;
  context->y = y;
  if (context->map != NULL)
    {
      SDL_FreeSurface(context->map);
      context->map = NULL;
    }
  if ((context->map = SDL_CreateRGBSurface(0, x * TILE_SIZE, y * TILE_SIZE,
					   32, RMASK, GMASK,
					   BMASK, AMASK)) == NULL)
    fprintf(stderr, "%s\n", SDL_GetError());
}
