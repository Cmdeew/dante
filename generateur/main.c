/*
** main.c for solver in /home/ploujo_c/rendu/ia
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Mon Apr 13 02:48:25 2015 Ploujoux Christophe
** Last update Fri May  8 11:31:29 2015 Ploujoux Christophe
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void	gene_imperfect(t_lab lab)
{
  lab.tab[0][0] = '*';
  if (lab.x > 2)
    lab.tab[0][lab.x - 1] = 'X';
  if (lab.y > 2)
    lab.tab[lab.y - 1][0] = 'X';
  lab.tab[lab.y - 1][lab.x - 1] = '*';
}

int	perfect_mod(char **argv)
{
  int	fd;
  char	**tab;

  if ((fd = open(my_strcat("../mazes/", argv[3]), O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
		 | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    {
      my_putstr("Erreur with open\n");
      return (1);
    }
  tab = gen_perfect(atoi(argv[1]), atoi(argv[2]));
  tab = draw_perfect(tab, atoi(argv[1]), atoi(argv[2]));
  fd_tab(tab, fd);
  return (0);
}

int		imperfect_mod(char **argv)
{
  t_lab		lab;
  int		fd;

  if ((fd = open(my_strcat("../mazes/", argv[3]), O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR
		 | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    {
      my_putstr("Erreur with open\n");
      return (1);
    }
  lab = init_lab(argv);
  gene_imperfect(lab);
  while (find_exit(lab) != 0)
    {
      lab = init_lab(argv);
      gene_imperfect(lab);
    }
  fd_tab(lab.tab, fd);
  return (0);
}

int	main(int argc, char **argv)
{

  if (argc < 4)
    {
      my_putstr("Usage: [columns] [line] [file_name] [gen perfect(1)]\n");
      return (1);
    }
  check_arg(argv);
  if (argc == 5 && atoi(argv[4]) == 1)
    if (perfect_mod(argv) == 1)
      return (1);
  if (argc == 4)
    if (imperfect_mod(argv) == 1)
      return (1);
  return (0);
}
