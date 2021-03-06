/*
** allum.h for allum1 in /home/toozs-_c/Prog_tests/allum1/sources/include
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Feb  4 09:48:14 2015 cristopher toozs-hobson
** Last update Fri Feb 13 17:40:02 2015 cristopher toozs-hobson
*/

#ifndef ALLUM_H_
#define ALLUM_H_

typedef struct	s_alum
{
  int		*map;
  int		clmn;
  int		line_nb;
  int		start;
  int		end;
  int		select;
  int		nb_slct;
}		t_alum;

void		make_tab(t_alum *a);
void		my_show_map(t_alum a);
void		ai_turn(t_alum *a, int *turn);
char		*convert_base(char *nbr, char *base_from, char *base_to);
void		game(t_alum *a, int game);
int		match_exist(int *map, int k);
void		select_line(t_alum *a);
void		select_num(t_alum *a);
int		subtractor(t_alum *a, int *line);
void		legend_display(int width);

#endif
