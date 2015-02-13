/*
** my_revstr.c for my_revstr in /home/toozs-_c/rendu/Piscine_C_J06/ex_03
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Oct  6 22:26:38 2014 cristopher toozs-hobson
** Last update Thu Feb 12 16:52:12 2015 cristopher toozs-hobson
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	a;
  int	b;
  int	c;

  a = 0;
  b = my_strlen(str) - 1;
  while (a < b)
    {
      c = str[a];
      str[a] = str[b];
      str[b] = c;
      a = a + 1;
      b = b - 1;
    }
  return (str);
}
