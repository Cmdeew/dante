/*
** aff.c for solveur in /home/ploujo_c/rendu/ia/dante/solveur
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Thu May  7 01:13:28 2015 Ploujoux Christophe
** Last update Thu May  7 02:32:41 2015 Ploujoux Christophe
*/

#include <stdlib.h>
#include "my.h"

int	**init_path(t_lab lab)
{
  int	i;
  int	**path;
  int	j;

  i = 0;
  path = malloc(sizeof(int *) * lab.y);
  while (i < lab.x)
    {
      j = 0;
      path[i] = malloc(sizeof(int) * lab.x);
      while (j < lab.x)
	{
	  path[i][j] = 0;
	  j++;
	}
      i++;
    }
  return (path);
}

int	**final_path(t_coord case_prev, t_coord **previous, t_lab lab)
{
  int	x;
  int	y;
  int	**path;

  x = lab.x - 1;
  y = lab.y - 1;
  path = init_path(lab);
  while (x != 0 || y != 0)
    {
      path[y][x] = 1;
      case_prev = previous[y][x];
      x = case_prev.x;
      y = case_prev.y;
    }
  path[0][0] = 1;
  return (path);
}

void	write_res(t_lab lab, t_coord **previous)
{
  int	x;
  int	y;
  int	**path;
  t_coord case_prev;

  path = final_path(case_prev, previous, lab);
  y = lab.y - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < lab.x)
	{
	  if (lab.tab[y][x] == '*')
	    {
	      if (path[y][x])
		lab.tab[y][x] = 'o';
	      else
		lab.tab[y][x] = '*';
	    }
	  else
	    lab.tab[y][x] = 'X';
	  x++;
	}
      y--;
    }
}
