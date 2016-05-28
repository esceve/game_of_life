/*
** game_of_life.c for game_of_life in /home/esceve/Documents/C/game_of_life
** 
** Made by Clement Scherpereel
** Login esceve <clement.scherpereel@outlook.fr>
** 
** Started on  Fri May 27 10:58:51 2016 Clement Scherpereel
** Last update Sat May 28 15:24:57 2016 Quentin Guerin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<signal.h>
#include	"SDLContext.h"
#include	"constants.h"
#include	"create_map.h"
#include	"test_cells.h"
#include	"display_map.h"

int		running = 1;

void		sighandler(int a)
{
  (void)a;
  running = 0;
}

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

int		main(void)
{
  int		map[SIZE][SIZE];
  void		*context;

  if ((context = SDLContext_init("Jeu de la vie", WIDTH, HEIGHT)) != NULL)
    {
      create_map(map);
      signal(SIGINT, sighandler);
      while (running == 1 && test_end_game(map) != 0)
	{
	  display_map(map);
	  printf("\nCellule viviantes : %d\n", test_end_game(map));
	  test_cells(map);
//	  test_end_game(map);
	  usleep(SLEEP_DURATION);
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
