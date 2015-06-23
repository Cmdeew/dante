/*
** asm.h for corewar in /home/rieux-_t/Projets/Modules/Elem/CPE_2014_corewar/asm/include
**
** Made by thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Sat Apr  4 17:38:11 2015 Thomas Rieux-Laucat
<<<<<<< HEAD
** Last update Tue May 12 17:33:51 2015 Ploujoux Christophe
=======
** Last update Wed May  6 17:45:36 2015 Ploujoux Christophe
>>>>>>> 353c0eac0becb7bc7e0f1b3b46fd76ab0ef1dbf9
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>

# define PERM S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP |  S_IROTH
# define TRUE 1
# define FALSE 0

typedef struct	s_lab
{
  char		**tab;
  int		**bool;
  int		x;
  int		y;
  int		fd;
}		t_lab;

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct	s_dir
{
  int		*dir_x;
  int		*dir_y;
}		t_dir;

void	check_arg(char **argv);
int	find_exit(t_lab lab);
int	count_all(t_lab lab, int x, int y);
int	count(char **tab, int x, int y);
char	*my_realloc(char *old, int size);
char	*get_next_line(const int fd);
t_lab	init_lab(char **argv);
t_lab	init_lab_solv(char *);
int	main(int argc, char **argv);
void    my_putchar(char c);
int	my_strlen(char *str);
void    my_putstr(char *str);
void	fd_putchar(char c, int fd);
void	fd_putstr(char *str, int fd);
void	my_free_tab(char **tab);
void	aff_tab(char **tab);
int	size_tab(char **tab);
void	*x_malloc(size_t n);
void	fd_tab(char **tab, int fd);
char	*my_strcat(char *, char *);
int	getNbrOfLine(char *);
char	**get_tab(char *);
void	put_err(char *);
t_dir	init_dir();
t_coord	**init_prev(t_lab lab);
void	write_res(t_lab lab, t_coord **previous);
char	**gen_perfect(int , int);
char	**draw_perfect(char **, int , int);
void	check_tab(char **tab);

#endif /* !MY_H_ */
