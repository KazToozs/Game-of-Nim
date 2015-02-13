/*
** ai.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Feb  9 16:38:58 2015 cristopher toozs-hobson
** Last update Fri Feb 13 18:04:45 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include "my.h"
#include "allum.h"

int			last_move(t_alum *a, int *i)
{
  int			exist;

  *i = -1;
  exist = 0;
  while (++(*i) < a->line_nb)
    if (a->map[*i] > 0)
      exist++;
  if (exist == 2)
    {
      *i = -1;
      while (++(*i) < a->line_nb)
	{
	  if (a->map[*i] == 1)
	    {
	      *i = -1;
	      while (++(*i) < a->line_nb)
		{
		  if (a->map[*i] > 1)
		    return (a->map[*i]);
		}
	    }
	}
    }
  return (-1);
}

int			xor(int *map, int lines)
{
  int			i;
  int			or;

  i = 0;
  or = 0;
  while (i < lines)
    {
      or = or ^ map[i];
      i++;
    }
  return (or);
}

int			*copy_map(int *map, int rows)
{
  int			*tmp;
  int			i;

  if ((tmp = malloc(sizeof(int) * rows)) == NULL)
    exit (0);
  i = 0;
  while (i < rows)
    {
      tmp[i] = map[i];
      i++;
    }
  return (tmp);
}

int			execute_xor(int *sub, t_alum *a, int i)
{
  int			*tmp;

  while (*sub < a->map[i])
    {
      tmp = copy_map(a->map, a->line_nb);
      tmp[i] = tmp[i] - *sub;
      if (xor(tmp, a->line_nb) == 0)
	{
	  free(tmp);
	  return (*sub);
	}
      *sub = *sub + 1;
      free(tmp);
    }
  return (-1);
}

int			subtractor(t_alum *a, int *line)
{
  int			sub;
  int			i;
  int			check;

  i = -1;
  if ((check = last_move(a, &i)) != -1)
    {
      *line = i + 1;
      return (check);
    }
  i = -1;
  while (i < a->line_nb)
    {
      i++;
      if (i < a->line_nb && a->map[i] > 0)
	{
	  sub = 1;
	  *line = i + 1;
	  if ((check = execute_xor(&sub, a, i)) != -1)
	    return (check);
	}
    }
  return (1);
}
