/*
** SDLContext.h for SDL_Context in /home/guerin_q/SDL_Context/includes
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 10:58:43 2016 Quentin Guerin
** Last update Sat May 28 18:13:11 2016 Quentin Guerin
*/

#ifndef		SDL_CONTEXT_HPP_
# define	SDL_CONTEXT_HPP_

# include	<SDL2/SDL.h>

struct SDLContext
{
  SDL_Window	*window;
  SDL_Renderer	*renderer;
  int		width;
  int		height;
  int		x;
  int		y;
};

void		*SDLContext_init(char *, int, int);
void		SDLContext_release(void **);
void		SDLContext_windowevent(void *context_ptr, SDL_Event *event);

#endif
