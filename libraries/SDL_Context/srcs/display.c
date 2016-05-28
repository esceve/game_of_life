/*
** display.c for SDLContext in /home/guerin_q/rendu/game_of_life/libraries/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 19:09:01 2016 Quentin Guerin
** Last update Sat May 28 20:25:08 2016 Quentin Guerin
*/

#include		"SDLContext.h"

void			SDLContext_display(void *context_ptr)
{
  struct SDLContext	*context;
  SDL_Rect		src;
  SDL_Texture		*texture;

  context = context_ptr;
  SDL_RenderClear(context->renderer);
  src.x = context->focus[0];
  src.y = context->focus[1];
  src.w = context->width < context->x * TILE_SIZE ?
    context->width : context->x * TILE_SIZE;
  src.h = context->height < context->y * TILE_SIZE ?
    context->height : context->y * TILE_SIZE;
  SDL_BlitSurface(context->map, &src, context->screen, NULL);
  texture = SDL_CreateTextureFromSurface(context->renderer, context->screen);
  if (texture == NULL)
    {
      fprintf(stderr, "%s\n", SDL_GetError());
      return ;
    }
  SDL_RenderCopy(context->renderer, texture, NULL, NULL);
  SDL_DestroyTexture(texture);
  SDL_RenderPresent(context->renderer);
}
