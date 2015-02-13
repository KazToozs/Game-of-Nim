/*
** my_getnbr_base.c for my_getnbr_base in /home/toozs-_c/rendu/Piscine_C_J08/lib/my
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Fri Oct 31 10:27:44 2014 cristopher toozs-hobson
** Last update Wed Feb 11 17:21:46 2015 cristopher toozs-hobson
*/

#include "my.h"

int     init(char *base, int *nbr, int *j, int *i)
{
  int   len;

  len = my_strlen(base);
  *nbr = 0;
  *j = 0;
  *i = 1;
  return (len);
}

int     check_neg(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (s[i] && (s[i] < '0' || s[i] > '9'))
    {
      if (s[i] == '-')
        {
          cpt = cpt + 1;
        }
      i = i + 1;
    }
  if (cpt % 2 == 0)
    {
      return (1);
    }
  return (-1);
}

int     check_base(char *base, int n)
{
  int   i;

  n = 0;
  while (base[n])
    {
      i = 0;
      while (base[i])
        {
          if (i != n)
            {
              if (base[n] == base[i])
                {
                  return (-1);
                }
            }
          i = i + 1;
        }
      n = n + 1;
    }
  return (0);
}

int     my_getnbr_base(char *str, char *base)
{
  int   nbr;
  int   len;
  int   j;
  int   k;
  int   i;

  len = init(base, &nbr, &j, &i);
  i = check_neg(str);
  if (check_base(base, 0) == -1)
    {
      return (0);
    }
  while (str[j])
    {
      k = 0;
      while (k < len && base[k] != str[j])
        k = k + 1;
      if (base[k] == str[j])
        nbr = nbr * len + k;
      else
        if ((str[j] != '-' && str[j] != '+'))
          return (0);
      j = j + 1;
    }
  return (nbr * i);
}
