/*
** convert_base.c for convert_base in /home/toozs-_c/rendu/Piscine_C_J08/ex_02
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Oct  9 13:37:14 2014 cristopher toozs-hobson
** Last update Thu Feb 12 17:58:44 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include "my.h"

char    *convert_base(char *nbr, char *base_from, char *base_to)
{
  int   i;
  int	j;
  int   nb;
  char  *res;

  i = 0;
  j = 1;
  if ((res = malloc(sizeof(char) * 300)) == NULL)
    exit(0);
  nb = my_getnbr_base(nbr, base_from);
  while (nb > 0)
    {
      if (i >= (j * 300))
	{
	  my_realloc(res, j * 300);
	  j++;
	}
      res[i] = base_to[nb % my_strlen(base_to)];
      nb = nb / my_strlen(base_to);
      i = i + 1;
    }
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}
