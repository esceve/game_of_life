/*
** SDLContext.h for SDL_Context in /home/guerin_q/SDL_Context/includes
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 10:58:43 2016 Quentin Guerin
** Last update Sat May 28 11:23:10 2016 Quentin Guerin
*/

#ifndef		SDL_CONTEXT_HPP_
# define	SDL_CONTEXT_HPP_

struct SDLContext
{
  SDL_Window	*window;
  SDL_Renderer	*renderer;
};

void		*SDLContext_init(char *, int, int);

#endif
