/*
** struct.c for ia in /home/ploujo_c/rendu/ia
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Tue May  5 14:21:43 2015 Ploujoux Christophe
<<<<<<< HEAD
** Last update Thu May  7 02:50:02 2015 Ploujoux Christophe
=======
** Last update Wed May  6 17:17:35 2015 Ploujoux Christophe
>>>>>>> 353c0eac0becb7bc7e0f1b3b46fd76ab0ef1dbf9
*/

#include "my.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int	**init_bool(t_lab lab)
{
  int	i;
  int	j;
  int	**bol;

  i = 0;
  bol = malloc(sizeof(int *) * lab.y);
  while (i < lab.y)
    {
      j = 0;
      bol[i] = malloc(sizeof(int) * lab.x);
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

t_coord		**init_prev(t_lab lab)
{
  t_coord	**previous;
  int		index;

  index = 0;
  previous = x_malloc(sizeof(previous) * lab.y);
  while (index < lab.y)
    {
      previous[index] = malloc(sizeof(*previous) * lab.x);
      index++;
    }
  return (previous);
}

t_dir	init_dir()
{
  t_dir	dir;

  dir.dir_x = malloc(sizeof(int) * 4);
  dir.dir_y = malloc(sizeof(int) * 4);
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

t_lab	init_lab_solv(char *file)
{
  t_lab	lab;

  lab.tab = get_tab(file);
  if (lab.tab != NULL && lab.tab[0] != NULL)
    lab.x = strlen(lab.tab[0]);
  else
    put_err("Error: file not correct.");
  lab.y = getNbrOfLine(file);
  lab.bool = init_bool(lab);
  return (lab);
}
