/*
** resize.c for SDLContext in /home/guerin_q/rendu/game_of_life/libraries/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 18:36:41 2016 Quentin Guerin
** Last update Sat May 28 18:43:49 2016 Quentin Guerin
*/

#include		"SDLContext.h"

void			SDLContext_resize(void *context_ptr, int width,
					  int height)
{
  struct SDLContext	*context;

  context = context_ptr;
  context->width = width;
  context->height = height;
  SDL_SetWindowSize(context->window, width, height);
  if (context->screen != NULL)
    SDL_FreeSurface(context->screen);
  if ((context->screen = SDL_CreateRGBSurface(0, width, height, 4,
					      RMASK, GMASK, BMASK,
					      AMASK)) == NULL)
    {
      fprintf(stderr, "%s\n", SDL_GetError());
      return ;
    }
}
