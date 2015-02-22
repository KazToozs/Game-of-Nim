/*
** main.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Feb  3 17:10:01 2015 cristopher toozs-hobson
** Last update Sun Feb 22 20:03:56 2015 cristopher toozs-hobson
*/

#include <ncurses/curses.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include "allum.h"
#include "my.h"

int		match_exist(int *map, int k)
{
  int		y;

  if (map != NULL)
    {
      y = 0;
      while (y < k)
        {
          if (map[y] > 0)
            return (1);
          y++;
        }
    }
  return (0);
}

void		ai_turn(t_alum *a, int *turn)
{
  int		line;
  int		sub;

  line = 0;
  sub = subtractor(a, &line);
  a->map[line - 1] = a->map[line - 1] - sub;
  *turn = 1;
  my_putstr("---------------\n");
  my_putstr("AI's move:\n");
  my_putstr("AI removed [");
  my_put_nbr(sub);
  if (sub > 1)
    my_putstr("] matches on line [");
  else if (sub == 1)
    my_putstr("] match on line [");
  my_put_nbr(line);
  my_putstr("]\n");
}

void		start_up(t_alum *a)
{
  int		nb;
  char		*ret;

  my_putstr("\033[H\033[2J");
  my_putstr("How many lines? (3->10): ");
  while ((nb = my_getnbr((ret = get_next_line(0)))) <= 2 || nb > 10)
    {
      free(ret);
      my_putstr("\033[H\033[2J");
      my_putstr("Invalid value; please enter a number between 3 and 10: ");
    }
  free(ret);
  a->line_nb = nb;
}

int		players()
{
  int		nb;
  char		*ret;

  my_putstr("\033[H\033[2J");
  my_putstr("1: 1 player\n");
  my_putstr("2: 2 players\n");
  my_putstr("Select a mode of play: ");
  while ((nb = my_getnbr((ret = get_next_line(0)))) <= 0 || nb > 2)
    {
      free(ret);
      my_putstr("\033[H\033[2J");
      my_putstr("1: 1 player\n");
      my_putstr("2: 2 players\n");
      my_putstr("Invalid value; please enter 1 or 2\n");
      my_putstr("Select a mode of play: ");
    }
  free(ret);
  return (nb);
}

int		main()
{
  int		mode;
  t_alum	a;

  mode = players();
  start_up(&a);
  if ((a.map = malloc(sizeof(int) * a.line_nb)) == NULL)
    return (1);
  make_tab(&a);
  my_putstr("\033[H\033[2J");
  legend_display(a.clmn);
  my_show_map(a);
  game(&a, mode);
  free(a.map);
  return (0);
}
