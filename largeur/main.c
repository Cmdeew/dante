/*
** main.c for ia in /home/ploujo_c/rendu/ia/dante/largeur
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri May  8 11:21:46 2015 Ploujoux Christophe
** Last update Fri May 15 21:27:32 2015 Ploujoux Christophe
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my.h"

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

int		main(int argc, char **argv)
{
  t_lab		lab;

  if (argc != 2)
    return (1);
  lab = init_lab_solv(argv[1]);
  check_tab(lab.tab);
  find_exit(lab);
  return (0);
}
