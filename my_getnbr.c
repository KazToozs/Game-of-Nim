/*
** my_getnbr.c for my_getnbr in /home/toozs-_c/rendu/Piscine_C_J04
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Oct  7 12:08:42 2014 cristopher toozs-hobson
** Last update Thu Feb 12 16:51:21 2015 cristopher toozs-hobson
*/

#include <unistd.h>

int     get_number(char *str, int i, int neg)
{
  int   nb;
  int   save;

  nb = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      save = nb;
      if (save > (nb * 10 + (str[i] - '0')))
        return (0);
      nb = nb * 10 + (str[i++] - '0');
    }
  if (neg % 2 == 1)
    nb = nb * -1;
  return (nb);
}

int     my_getnbr(char *str)
{
  int   i;
  int   nb;
  int   neg;

  if (str != NULL)
    {
      i = 0;
      neg = 0;
      while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
	{
	  if (str[i] == '-')
	    neg++;
	  if (str[i] >= '0' && str[i] <= '9')
	    {
	      nb = get_number(str, i, neg);
	      return (nb);
	    }
	  i++;
	}
    }
  return (0);
}
