/*
** tab_functions.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Feb  3 17:36:57 2015 cristopher toozs-hobson
** Last update Fri Feb 13 17:55:55 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "allum.h"

void		make_tab(t_alum *a)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  a->clmn = 1 + (2 * (a->line_nb + 1));
  while (i < a->line_nb)
    {
      a->map[i] = count;
      count = count + 2;
      i++;
    }
}
void		line_count(int i)
{
  my_putstr("  [");
  my_put_nbr(i + 1);
  my_putstr("] ");
  if (i < 9)
    my_putchar(' ');
}

void		match_count(int *tab, int y)
{
  my_putstr(" [ | = ");
  my_put_nbr(tab[y]);
  my_putstr("]\n");
}

void		legend_display(int width)
{
  int		i;

  i = -2;
  my_putstr("line:");
  while (i <= width)
    {
      my_putchar(' ');
      i++;
    }
  my_putstr("matches\n");
}

void		my_show_map(t_alum a)
{
  int		y;
  int		x;
  int		count;

  y = 0;
  while (y < a.line_nb)
    {
      x = 0;
      line_count(y);
      count = a.map[y];
      while (x < a.clmn)
        {
          a.start = a.line_nb - ((a.map[y] + 1) / 2);
          if (x > a.start && count > 0)
            {
              my_putchar('|');
              count--;
            }
          else
            my_putchar(' ');
          x++;
        }
      match_count(a.map, y);
      y++;
    }
}
