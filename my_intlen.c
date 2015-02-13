/*
** my_intlen.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Feb 11 17:05:49 2015 cristopher toozs-hobson
** Last update Wed Feb 11 17:07:01 2015 cristopher toozs-hobson
*/

int		my_intlen(int nb)
{
  int		i;

  i = 1;
  while (nb >= 10)
    {
      i++;
      nb = nb / 10;
    }
  return (i);
}
