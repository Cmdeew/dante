/*
** error.c for dante in /home/rieux-_t/Projets/Modules/IA/dante/solveur
** 
** Made by 
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed May  6 18:02:46 2015 
** Last update Sat May 16 12:50:26 2015 Ploujoux Christophe
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	put_err(char *str)
{
  printf("%s\n", str);
  exit(EXIT_FAILURE);
}

int	check_char(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] != '*' && tab[i][j] != 'X' && tab[i][j] != '\n')
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_size(char **tab)
{
  int	i;
  int	save;

  save = my_strlen(tab[0]);
  i = 1;
  while (tab[i])
    {
      if (my_strlen(tab[i]) != save)
	return (1);
      i++;
    }
  return (0);
}

void	check_tab(char **tab)
{
  if (check_char(tab) == 1)
    put_err("One character is not * or X");
  if (check_size(tab) == 1)
    put_err("The lab is not a rectangle");
}
