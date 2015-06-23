/*
** profondeur.c for dante in /home/rieux-_t/Projets/Modules/IA/dante/solveur
**
** Made by Thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Wed May  6 17:11:22 2015 Thomas Rieux-Laucat
** Last update Tue May 12 17:39:14 2015 Ploujoux Christophe
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "get_next_line.h"

int	getNbrOfLine(char *file)
{
  int	fd;
  char	*str;
  int	i;

  i = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  while ((str = get_next_line(fd)))
    i++;
  close(fd);
  return (i);
}

char	**get_tab(char *file)
{
  int	fd;
  int	i;
  int	line;
  char	*str;
  char	**tab;

  i = 0;
  line = getNbrOfLine(file);
  if (line > 100)
    put_err("Error: this map is to bis ( map size > 100 )");
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  tab = x_malloc(sizeof(char *) * (line + 1));
  while ((str = get_next_line(fd)))
    {
      tab[i] = str;
      i++;
    }
  tab[i] = NULL;
  close(fd);
  return (tab);
}


void	create_solution(char **tab)
{
  int	fd;

  if ((fd = open("solution", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
		 | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    put_err("Error open...");

  fd_tab(tab, fd);
}

void		findTheWayRec(t_lab lab, int x, int y, t_coord **previous)
{
  int		way, x2, y2;
  t_dir		dir;

  way = 0;
  dir = init_dir();
  if (x == lab.x - 1 && y == lab.y - 1)
    {
      write_res(lab, previous);
      aff_tab(lab.tab);
      create_solution(lab.tab);
      return;
    }
  while (way < 4)
    {
      x2 = x + dir.dir_x[way];
      y2 = y + dir.dir_y[way];
      if ((x2 >= 0 && x2 < lab.x && y2 >= 0 && y2 < lab.y
	   && lab.tab[y2][x2] == '*' && !lab.bool[y2][x2]))
	{
	  previous[y2][x2].x = x;
	  previous[y2][x2].y = y;
	  lab.bool[y2][x2] = 1;
	  findTheWayRec(lab, x2, y2, previous);
	}
      way++;
    }
}

int		main(int argc, char **argv)
{
  t_coord	**previous;
  t_lab		lab;

  if (argc != 2)
    return (1);
  lab = init_lab_solv(argv[1]);
  check_tab(lab.tab);
  previous = init_prev(lab);
  findTheWayRec(lab, 0, 0, previous);
  return (0);
}
