/*
** display_map.c for jeu de la vie in /home/guerin_q/rendu/game_of_life/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 14:01:34 2016 Quentin Guerin
<<<<<<< HEAD
** Last update Sat May 28 18:34:15 2016 Clement Scherpereel
=======
** Last update Sat May 28 20:25:52 2016 Quentin Guerin
>>>>>>> 59515082b54718eacdb5523f359a28db9b47466d
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"create_map.h"

void		display_map(int tab[SIZE][SIZE])
{
  int		i;
  int		j;

  system("clear");
  for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
	printf(" %c ", tab[i][j] == 1 ? 'X' : ' ');
      printf("\n");
    }
}
