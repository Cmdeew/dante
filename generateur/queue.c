/*
** queue.c for ia in /home/ploujo_c/rendu/ia
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Wed May  6 13:32:45 2015 Ploujoux Christophe
<<<<<<< HEAD
** Last update Fri May  8 11:33:40 2015 Ploujoux Christophe
=======
** Last update Wed May  6 17:44:19 2015 Ploujoux Christophe
>>>>>>> 353c0eac0becb7bc7e0f1b3b46fd76ab0ef1dbf9
*/

#include <stdlib.h>
#include "my.h"

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

int	loop(t_coord **previous, t_coord *queue, t_lab lab, t_dir dir)
{
  int	x;
  int	y;
  int	x2;
  int	y2;
  int	d;

  while (end > beg)
    {
      tail_rem(&x, &y, queue);
      if (x == lab.x - 1 && y == lab.y - 1)
	return (0);
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
