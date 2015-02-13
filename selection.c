/*
** selection.c for allum1 in /home/toozs-_c/Prog_tests/allum1/backup4
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Feb 12 17:37:31 2015 cristopher toozs-hobson
** Last update Fri Feb 13 16:41:47 2015 cristopher toozs-hobson
*/

#include <unistd.h>
#include <stdlib.h>
#include "allum.h"
#include "my.h"

int		check_line(t_alum a, int nb)
{
  if (a.map)
    {
      if (a.map[nb] <= 0)
	return (0);
    }
  return (1);
}

void		select_line(t_alum *a)
{
  int		nb;
  char		*ret;

  my_putstr("Select a line to remove matches from: ");
  while (((nb = my_getnbr((ret = get_next_line(0)))) <= 0 || nb > a->line_nb)
         || check_line(*a, nb - 1) == 0)
    {
      free(ret);
      if (nb <= 0 || nb > a->line_nb)
        my_putstr("Invalid number; that line does not exist.\n");
      else if (check_line(*a, nb - 1) == 0)
        my_putstr("Invalid number; that line is empty.\n");
      my_putchar('\n');
      my_putstr("Select a line to remove matches from: ");
    }
  free(ret);
  a->select = nb;
}

void		my_error(char *str, int **map)
{
  int		i;

  i = 0;
  free(map);
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
  exit(1);
}

void		select_num(t_alum *a)
{
  int		nb;
  char		*ret;

  my_putstr("Select a number of matches to remove: ");
  while ((nb = my_getnbr((ret = get_next_line(0)))) <= 0
	 || nb > a->map[a->select - 1])
    {
      free(ret);
      if (nb <= 0)
        my_putstr("Invalid value; value must be positive.\n");
      else if (nb > a->map[a->select - 1])
        my_putstr("Invalid value: not an existing number of matches.\n");
      my_putchar('\n');
      my_putstr("Select a number of matches to remove: ");
    }
  free(ret);
  a->nb_slct = nb;
}
