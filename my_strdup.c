/*
** my_strdup.c for my_strdup in /home/toozs-_c/rendu/Piscine_C_J08/ex_01
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Nov  5 17:02:51 2014 cristopher toozs-hobson
** Last update Sat Jan 31 00:51:05 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *str)
{
  char	*dest;

  dest = (char *)malloc(sizeof(char) * my_strlen(str) + 1);
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
