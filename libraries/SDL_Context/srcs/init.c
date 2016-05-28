/*
** init.c for SDL_Context in /home/guerin_q/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 10:27:06 2016 Quentin Guerin
** Last update Sat May 28 15:22:37 2016 Quentin Guerin
*/

#include	"SDLContext.h"

void		*SDLContext_init(char *window_title, int width, int height)
{
  struct SDLContext *context;

  if ((context = malloc(sizeof(struct SDLContext))) == NULL)
    return (NULL);
  if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
      if ((context->window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED,
					      SDL_WINDOWPOS_UNDEFINED, width, height,
					      SDL_WINDOW_RESIZABLE |
					      SDL_WINDOW_HIDDEN)) != NULL) {
	if ((context->renderer = SDL_CreateRenderer(context->window, -1,
						    SDL_RENDERER_ACCELERATED)) != NULL) {
	  context->width = width;
	  context->height = height;
	  context->x = 0;
	  context->y = 0;
	  return (context);
	}
      }
    }
  printf("%s\n", SDL_GetError());
  return (NULL);
}
