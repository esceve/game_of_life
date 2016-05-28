/*
** create_map.c for jeu de la vie in /home/guerin_q/rendu/game_of_life/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 13:59:23 2016 Quentin Guerin
** Last update Sat May 28 14:48:28 2016 Quentin Guerin
*/

#include	<stdlib.h>
#include	<time.h>
#include	"create_map.h"

void		create_map(int tab[SIZE][SIZE])
{
  int		i;
  int		j;

  srand(time(NULL));
  for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
	{
	  if (rand() % 100 < 15)
	    tab[i][j] = 1;
	  else
	    tab[i][j] = 0;
	}
    }
}
