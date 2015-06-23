/*
** str2.c for str2 in /home/ploujo_c/rendu/unix/PSU_2014_minishell1
** 
** Made by Ploujoux Christophe
** Login   <ploujo_c@epitech.net>
** 
** Started on  Tue Jan 27 02:56:37 2015 Ploujoux Christophe
<<<<<<< HEAD
** Last update Wed May  6 13:42:29 2015 Ploujoux Christophe
=======
** Last update Thu Apr  9 15:17:00 2015 Ploujoux Christophe
>>>>>>> a6bea7b2e94b72351994f9445e9cd5a606dff329
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void    my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	fd_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

void	fd_putstr(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}
