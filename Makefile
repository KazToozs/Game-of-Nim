##
## Makefile for Allum1 in /home/toozs-_c/rendu/C_Prog_Elem/Allum1
## 
## Made by cristopher toozs-hobson
## Login   <toozs-_c@epitech.net>
## 
## Started on  Tue Feb  3 12:32:39 2015 cristopher toozs-hobson
## Last update Sun Feb 22 20:10:08 2015 cristopher toozs-hobson
##

SRC	=	my_putstr.c		\
		my_putchar.c		\
		my_getnbr.c		\
		my_put_nbr.c		\
		get_next_line.c		\
		tab_functions.c		\
		my_strlen.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_to_wordtab.c	\
		my_strcmp.c		\
		gameplay.c		\
		ai.c			\
		my_getnbr_base.c	\
		my_revstr.c		\
		convert_base.c		\
		my_realloc.c		\
		selection.c		\
		main.c

NAME	=	allum1

CC	=	gcc

COMP	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

CFLAGS	+=	-I./sources/include

LDFLAGS	=	-L./ -lncurses

all: $(NAME)

$(NAME): $(COMP)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS)

clean: 
	rm -f $(COMP)

fclean: clean
	rm -f $(NAME)

re: fclean all
