/*
** test_cells.c for jeu de la vie in /home/guerin_q/rendu/game_of_life/srcs
** 
** Made by Quentin Guerin
** Login   <guerin_q@epitech.net>
** 
** Started on  Sat May 28 14:04:27 2016 Quentin Guerin
** Last update Sat May 28 14:48:09 2016 Quentin Guerin
*/

#include	"create_map.h"

static int	count_neighbours(int tab[SIZE][SIZE], int i, int j)
{
  int		neighbours;

  neighbours = 0;
  if(j > 0 && tab[i][j-1]==1)
    neighbours++;
  //bas
  if(j < SIZE - 1 && tab[i][j+1]==1)
    neighbours++;
  //gauche
  if(i > 0 && tab[i-1][j]==1)
    neighbours++;
  //droite
  if(i < SIZE - 1 && tab[i+1][j]==1)
    neighbours++;
  //haut gauche
  if(i > 0 && j > 0 && tab[i-1][j-1]==1)
    neighbours++;
  //haut droite
  if(i < SIZE - 1 && j > 0 && tab[i+1][j-1]==1)
    neighbours++;
  //bas droite
  if(i < SIZE - 1 && j < SIZE - 1 && tab[i+1][j+1]==1)
    neighbours++;
  //bas gauche
  if(i > 0 && j < SIZE - 1 && tab[i-1][j+1]==1)
    neighbours++;
  return (neighbours);
}

void		test_cells(int tab[SIZE][SIZE])
{
  int		i;
  int		j;
  int		neighbours;

  for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
	{
	  neighbours = count_neighbours(tab, i, j);
	  if (neighbours == 3)
	    tab[i][j] = 1;
/*	  if (neighbours == 2)
	    tab[i][j] = tab[i][j];*/
	  if (neighbours < 2)
	    tab[i][j] = 0;
	  if (neighbours > 3)
	    tab[i][j] = 0;
	}
    }
}
