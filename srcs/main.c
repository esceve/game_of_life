/*
** game_of_life.c for game_of_life in /home/esceve/Documents/C/game_of_life
**
** Made by Clement Scherpereel
** Login esceve <clement.scherpereel@outlook.fr>
**
** Started on  Fri May 27 10:58:51 2016 Clement Scherpereel
<<<<<<< HEAD
** Last update Sat May 28 23:25:39 2016 Clement Scherpereel
=======
** Last update Sat May 28 21:20:23 2016 Quentin Guerin
>>>>>>> 59515082b54718eacdb5523f359a28db9b47466d
*/

#include	<time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<signal.h>
#include	"constants.h"
#include	"SDLContext.h"
#include	"create_map.h"
#include	"test_cells.h"
#include	"display_map.h"

int		test_end_game(int tab[SIZE][SIZE])
{
  int		i;
  int		j;
  int		verif;

  verif = 0;
  for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
	if (tab[i][j] == 1)
	 verif++;
    }
  return (verif);
}

int			main(void)
{
  int			map[SIZE][SIZE];
  void			*context;
  SDL_Event		event;
  int			running;
  struct timespec	now;
  struct timespec	now_tmp;
  size_t		accum;

  if ((context = SDLContext_init("Jeu de la vie", WIDTH, HEIGHT)) != NULL)
    {
      running = 1;
      SDLContext_initscreen(context);
      create_map(map);
      SDLContext_setmapsize(context, SIZE, SIZE);
      clock_gettime(CLOCK_MONOTONIC, &now);
      while (running == 1 && test_end_game(map) != 0)
	{
	  clock_gettime(CLOCK_MONOTONIC, &now_tmp);
	  accum = ((now_tmp.tv_sec - now.tv_sec) * 1000000000);
	  accum += (now_tmp.tv_nsec - now.tv_nsec);
	  if (((double)(accum) / 1000000000) > SLEEP_DURATION)
	    {
	      now.tv_sec = now_tmp.tv_sec;
	      now.tv_nsec = now_tmp.tv_nsec;
	      SDLContext_loadmap(context, (int*)map);
	  //    display_map(map);
	      SDLContext_display(context);
	  //    printf("\nCellule viviantes : %d\n", test_end_game(map));
	      test_cells(map);
	    }
	  if (SDL_PollEvent(&event))
	    {
	      if (event.type == SDL_QUIT)
		running = 0;
	      else if (event.type == SDL_WINDOWEVENT)
		SDLContext_windowevent(context, &event);
	    }
	}
      if (running == 1)
	{
	  display_map(map);
	  printf("FIN DU JEU, TOUT LE MONDE EST MORT\n\n");
	}
      SDLContext_release(&context);
    }
  return(EXIT_SUCCESS);
}
