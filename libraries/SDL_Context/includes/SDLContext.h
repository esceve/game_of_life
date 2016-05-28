/*
** SDLContext.h for SDL_Context in /home/guerin_q/SDL_Context/includes
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 10:58:43 2016 Quentin Guerin
** Last update Sat May 28 21:08:39 2016 Quentin Guerin
*/

#ifndef SDL_CONTEXT_HPP_
# define SDL_CONTEXT_HPP_

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# if SDL_BYTEORDER == SDL_BIG_ENDIAN
#  define RMASK 0xff000000
#  define GMASK 0x00ff0000
#  define BMASK 0x0000ff00
#  define AMASK 0x000000ff
# else
#  define AMASK 0xff000000
#  define BMASK 0x00ff0000
#  define GMASK 0x0000ff00
#  define RMASK 0x000000ff
# endif

# define TILE_SIZE 32

# define IMG1_PATH "./data/img1.bmp"
# define IMG2_PATH "./data/img2.bmp"
# define IMG3_PATH "./data/img3.bmp"

struct SDLContext
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *screen;
  SDL_Surface *map;
  SDL_Texture *screen_texture;
  int width;
  int height;
  int x;
  int y;
  int focus[2];
};

void *SDLContext_init(char *, int, int);
void SDLContext_initscreen(void *);
void SDLContext_release(void **);
void SDLContext_windowevent(void *context_ptr, SDL_Event *event);
void SDLContext_setmapsize(void *, int, int);
void SDLContext_resize(void *, int, int);
void SDLContext_display(void *);
void SDLContext_loadmap(void *, int *);

extern SDL_Surface *img1;
extern SDL_Surface *img2;
extern SDL_Surface *img3;

#endif
