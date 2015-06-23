/*
** struct.c for ia in /home/ploujo_c/rendu/ia
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Tue May  5 14:21:43 2015 Ploujoux Christophe
** Last update Wed May  6 17:44:06 2015 Ploujoux Christophe
*/

#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "my.h"

int	**init_bool(t_lab lab)
{
  int	i;
  int	j;
  int	**bol;

  i = 0;
  bol = x_malloc(sizeof(int *) * lab.y);
  while (i < lab.y)
    {
      j = 0;
      bol[i] = x_malloc(sizeof(int) * lab.x);
      while (j < lab.x)
	{
	  bol[i][j]  = FALSE;
	  j++;
	}
      i++;
    }
  bol[0][0] = TRUE;
  return (bol);
}

char	**init_tab(t_lab lab)
{
  int	i;
  int	j;
  char	**tab;

  i = 0;
  srand(time(NULL));
  tab = x_malloc(sizeof(char *) * (lab.y + 1));
  while (i < lab.y)
    {
      tab[i] = x_malloc(sizeof(char) * (lab.x + 1));
      j = 0;
      while (j < lab.x)
	{
	  if (rand() % 3 < 1)
	    tab[i][j] = 'X';
	  else
	    tab[i][j] = '*';
	  j++;
	}
      tab[i][j] = '\0';
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

t_lab	init_lab(char **argv)
{
  t_lab	lab;

  lab.x = atoi(argv[1]);
  lab.y = atoi(argv[2]);
  lab.tab = init_tab(lab);
  lab.bool = init_bool(lab);
  return (lab);
}

t_dir	init_dir()
{
  t_dir	dir;

  dir.dir_x = x_malloc(sizeof(int) * 4);
  dir.dir_y = x_malloc(sizeof(int) * 4);
  dir.dir_x[0] = 1;
  dir.dir_x[1] = -1;
  dir.dir_x[2] = 0;
  dir.dir_x[3] = 0;
  dir.dir_y[0] = 0;
  dir.dir_y[1] = 0;
  dir.dir_y[2] = 1;
  dir.dir_y[3] = -1;
  return (dir);
}

t_coord		**init_prev(t_lab lab)
{
  t_coord	**previous;
  int		index;

  index = 0;
  previous = x_malloc(sizeof(previous) * lab.y);
  while (index < lab.y)
    {
      previous[index] = x_malloc(sizeof(*previous) * lab.x);
      index++;
    }
  return (previous);
}
