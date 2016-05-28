/*
** loadmap.c for SDLContext in /home/guerin_q/rendu/game_of_life/libraries/SDL_Context/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 19:59:28 2016 Quentin Guerin
** Last update Sat May 28 21:13:51 2016 Quentin Guerin
*/

#include		"SDLContext.h"

void			SDLContext_loadmap(void *context_ptr, int *map)
{
  ssize_t		y;
  ssize_t		x;
  SDL_Rect		dst;
  struct SDLContext	*context;

  context = context_ptr;
  dst.w = TILE_SIZE;
  dst.h = TILE_SIZE;
  if (img1 == NULL || img2 == NULL || img3 == NULL)
    {
      img1 = IMG_Load(IMG1_PATH);
      img2 = IMG_Load(IMG2_PATH);
      img3 = IMG_Load(IMG3_PATH);
    }
  SDL_FillRect(context->map, NULL, SDL_MapRGB(context->map->format, 0, 0, 0));
  for (y = 0; y < context->y; y++)
    {
      for (x = 0; x < context->x; x++)
	{
	  dst.x = x * dst.w;
	  dst.y = y * dst.h;
	  if (map[y * context->y + x] == 1)
	    SDL_BlitSurface(img1, NULL, context->map, &dst);
	  else if (map[y * context->y + x] == 2)
	    SDL_BlitSurface(img2, NULL, context->map, &dst);
	  else if (map[y * context->y + x] == 3)
	    SDL_BlitSurface(img3, NULL, context->map, &dst);
	}
    }
}
