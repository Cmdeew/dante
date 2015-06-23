/*
** check.c for ia in /home/ploujo_c/rendu/ia/dante/generateur
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri May  8 11:30:33 2015 Ploujoux Christophe
** Last update Fri May  8 11:31:28 2015 Ploujoux Christophe
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void	check_arg(char **argv)
{
  if (atoi(argv[1]) < 2 && atoi(argv[2]) < 2)
    {
      printf("Number of columns or lines must be bigger (need columns/lines > 1)\n");
      exit(EXIT_FAILURE);
    }
}
