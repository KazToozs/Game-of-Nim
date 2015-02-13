/*
** gameplay.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Fri Feb  6 16:29:43 2015 cristopher toozs-hobson
** Last update Fri Feb 13 17:56:18 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include "allum.h"
#include "my.h"

void		end_game(int turn, int mode)
{
  if (mode == 1)
    {
      if (turn == 1)
	my_putstr("You win!\n");
      else
	my_putstr("You lose!\n");
    }
  else if (mode == 2)
    {
      if (turn == 1)
	my_putstr("Player 1 wins!\n");
      else
	my_putstr("Player 2 wins!\n");
    }
}

void		player_turn(int turn)
{
  if (turn == 1)
    my_putstr("Player 1's turn\n");
  else
    my_putstr("Player 2's turn\n");
}

void		two_player(t_alum *a, int *turn)
{
  player_turn(*turn);
  select_line(a);
  select_num(a);
  my_putstr("\033[H\033[2J");
  my_putstr("Previous:\n");
  legend_display(a->clmn);
  my_show_map(*a);
  a->map[a->select - 1] = a->map[a->select - 1] - a->nb_slct;
  my_putstr("----------------------\n");
  my_putstr("Current: \n");
  legend_display(a->clmn);
  my_show_map(*a);
  if (*turn == 1)
    *turn = 2;
  else
    *turn = 1;
}

void		one_player(t_alum *a, int *turn)
{
  if (*turn == 1)
    {
      select_line(a);
      select_num(a);
      my_putstr("\033[H\033[2J");
      my_putstr("Previous:\n");
      legend_display(a->clmn);
      my_show_map(*a);
      a->map[a->select - 1] = a->map[a->select - 1] - a->nb_slct;
      my_putstr("---------------\n");
      my_putstr("Your move: \n");
      legend_display(a->clmn);
      my_show_map(*a);
      *turn = 2;
    }
  else
    {
      ai_turn(a, turn);
      legend_display(a->clmn);
      my_show_map(*a);
    }
}

void		game(t_alum *a, int game)
{
  int		turn;

  turn = 1;
  while (match_exist(a->map, a->line_nb) == 1)
    {
      if (game == 1)
	one_player(a, &turn);
      else
	two_player(a, &turn);
    }
  end_game(turn, game);
}
