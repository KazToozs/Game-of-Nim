/*
** my.h for my_h in /home/toozs-_c/rendu/Piscine_C_J09/include
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Fri Oct 10 14:21:53 2014 cristopher toozs-hobson
** Last update Fri Feb 13 16:57:15 2015 cristopher toozs-hobson
*/

#ifndef LIB_MY_
# define LIB_MY_

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
int		my_getnbr(char *str);
char		*get_next_line(int fd);
int		my_strcmp(char *s1, char *s2);
int		my_strlen(char *str);
char		*my_strdup(char *str);
char		*my_strcpy(char *dest, char *src);
char		**my_str_tab(char *str);
int		my_intlen(int nb);
char		*my_int_to_str(int nb);
char		*my_revstr(char *str);
int		my_getnbr_base(char *str, char *base);
char		*my_realloc(char *buffer, int size);

#endif
