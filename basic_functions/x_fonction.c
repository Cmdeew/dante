/*
** base_fonction.c for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Thu Jan 15 17:06:40 2015 thomas rieux-laucat
** Last update Wed May  6 18:12:39 2015 
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	*x_malloc(size_t n)
{
  char	*tab;

  tab = malloc(n);
  if (tab == NULL)
    {
      my_putstr("Error with malloc\n");
      exit(EXIT_FAILURE);
    }
  return (tab);
}
