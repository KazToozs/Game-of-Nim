/*
** my_int_to_str.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Feb 11 17:05:04 2015 cristopher toozs-hobson
** Last update Thu Feb 12 11:38:54 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include "my.h"

char		*my_int_to_str(int nb)
{
  char		*str;
  int		i;

  i = 0;
  str = malloc(sizeof(char) * (my_intlen(nb) + 1));
  while (nb >= 10)
    {
      str[i] = (nb % 10 + '0');
      i++;
      nb = nb / 10;
    }
  str[i] = (nb % 10 + '0');
  str[i + 1] = '\0';
  return (my_revstr(str));
}
