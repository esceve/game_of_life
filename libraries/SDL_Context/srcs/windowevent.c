/*
** windowevent.c for SDLContext in /home/guerin_q/rendu/game_of_life/libraries/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 18:07:56 2016 Quentin Guerin
** Last update Sat May 28 18:43:14 2016 Quentin Guerin
*/

#include		"SDLContext.h"

void			SDLContext_windowevent(void *context_ptr,
					       SDL_Event *event)
{
  struct SDLContext	*context;

  context = context_ptr;
  if (event->type == SDL_WINDOWEVENT)
    {
      switch (event->window.event)
	{
	  case SDL_WINDOWEVENT_RESIZED:
	    context->width = event->window.data1;
	    context->height = event->window.data2;
	    break;
	  default:
	    break;
	}
    }
}
