/*
** get_next_line.c for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
**
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Tue Jan 20 11:43:56 2015 thomas rieux-laucat
** Last update Wed May  6 18:11:54 2015 
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"

char	*my_realloc(char *old, int size)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(sizeof(*new) * (my_strlen(old) + size) + 2)) == NULL)
    return (NULL);
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  return (new);
}

char	*get_next_line(const int fd)
{
  char	buff;
  int	i;
  int	rd;
  char	*line;

  i = 0;
  line = x_malloc(sizeof(char *));
  if ((rd = read(fd, &buff, 1)) == -1)
    return (NULL);
  if (rd == 0)
    return (NULL);
  while (buff != '\n')
    {
      line = my_realloc(line, 1);
      line[i] = buff;
      read(fd, &buff, 1);
      i++;
    }
  line[i] = '\0';
  return (line);
}
