/*
** display_map.c for jeu de la vie in /home/guerin_q/rendu/game_of_life/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 14:01:34 2016 Quentin Guerin
** Last update Sat May 28 18:34:15 2016 Clement Scherpereel
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
