/*
** main.c for dante in /home/rieux-_t/Projets/Modules/IA/dante
** 
** Made by 
** Login   <rieux-_t@epitech.net>
** 
** Started on  Thu May  7 13:18:18 2015 
** Last update Thu May  7 16:01:50 2015 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**gen_perfect(int x, int y)
{
  int	i;
  int	j;
  char	**tab;

  i = 0;
  tab = malloc(sizeof(char *) * (y + 1));
  while (i < y)
    {
      j = 0;
      tab[i] = malloc(sizeof(char) * (x + 1));
      while (j < x)
	tab[i][j++] = '*';
      tab[i][j] = '\0';
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

char	**draw_perfect(char **tab, int x, int y)
{
  int	i;
  int	j;

  i = 1;
  while (i < y)
    {
      j = 0;
      while (j < x)
	tab[i][j++] = 'x';
      if (i+1 == y)
	tab[i][x-1] = '*';
      else
	tab[i][rand() % x] = '*';
      if (i+1 == y)
	i++;
      else
	i+= 2;
    }
  return (tab);
}
