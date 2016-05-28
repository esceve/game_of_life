/*
** init.c for SDL_Context in /home/guerin_q/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 10:27:06 2016 Quentin Guerin
** Last update Sat May 28 21:11:29 2016 Quentin Guerin
*/

#include		"SDLContext.h"

SDL_Surface		*img1 = NULL;
SDL_Surface		*img2 = NULL;
SDL_Surface		*img3 = NULL;

void			SDLContext_initscreen(void *context_ptr)
{
  struct SDLContext	*context;

  context = context_ptr;
  SDL_FillRect(context->screen, NULL, 0x00000000);
  SDL_FillRect(context->map, NULL, 0x00000000);
}

void		*SDLContext_init(char *window_title, int width, int height)
{
  struct SDLContext *context;

  if ((context = malloc(sizeof(struct SDLContext))) == NULL)
    return (NULL);
  context->x = 0;
  context->y = 0;
  context->map = NULL;
  context->screen = NULL;
  context->screen_texture = NULL;
  context->focus[0] = 0;
  context->focus[1] = 0;
  if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
      if ((context->window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED,
					      SDL_WINDOWPOS_UNDEFINED, width, height,
					      SDL_WINDOW_RESIZABLE)) != NULL) {
	if ((context->renderer = SDL_CreateRenderer(context->window, -1,
						    SDL_RENDERER_ACCELERATED)) != NULL) {
	  context->width = width;
	  context->height = height;
	  if ((context->screen = SDL_CreateRGBSurface(0, width, height, 32,
						      RMASK, GMASK, BMASK,
						      AMASK)) != NULL)
	    return (context);
	}
      }
    }
  printf("%s\n", SDL_GetError());
  return (NULL);
}
