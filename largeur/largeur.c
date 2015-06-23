/*
** profondeur.c for dante in /home/rieux-_t/Projets/Modules/IA/dante/solveur
**
** Made by Thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Wed May  6 17:11:22 2015 Thomas Rieux-Laucat
** Last update Fri May  8 11:28:45 2015 Ploujoux Christophe
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "get_next_line.h"

int	beg;
int	end;

void	tail_add(int x, int y, t_coord *queue)
{
  queue[end].x = x;
  queue[end].y = y;
  end++;
}

void	tail_rem(int *x, int *y, t_coord *queue)
{
  *x = queue[beg].x;
  *y = queue[beg].y;
  beg++;
}

void	create_solution(char **tab)
{
  int	fd;

  if ((fd = open("solution", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
		 | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    put_err("Error open...");
  fd_tab(tab, fd);
}

int	loop(t_coord **previous, t_coord *queue, t_lab lab, t_dir dir)
{
  int	x, y, x2, y2, d;

  while (end > beg)
    {
      tail_rem(&x, &y, queue);
      if (x == lab.x - 1 && y == lab.y - 1)
	{
	  write_res(lab, previous);
	  aff_tab(lab.tab);
	  create_solution(lab.tab);
	  return (0);
	}
      d = 0;
      while (d < 4)
	{
	  x2 = x + dir.dir_x[d];
	  y2 = y + dir.dir_y[d];
	  if (x2 >= 0 && x2 < lab.x && y2 >= 0 && y2 < lab.y
	      && lab.tab[y2][x2] == '*' && !lab.bool[y2][x2])
	    {
	      previous[y2][x2].x = x;
	      previous[y2][x2].y = y;
	      tail_add(x2, y2, queue);
	      lab.bool[y2][x2] = 1;
	    }
	  d++;
	}
    }
  return (1);
}

int		find_exit(t_lab lab)
{
  t_coord	**previous;
  t_coord	*queue;
  t_dir		dir;

  beg = 0;
  end = 0;
  dir = init_dir();
  previous = init_prev(lab);
  queue = x_malloc(sizeof(*queue) * (lab.y * lab.x));
  tail_add(0, 0, queue);
  lab.bool[0][0] = 1;
  if (loop(previous, queue, lab, dir) == 0)
    return (0);
  return (1);
}
