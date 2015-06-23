##
## Makefile for minitalk in /home/ploujo_c/rendu/unix/PSU_2014_minitalk
## 
## Made by Ploujoux Christophe
## Login   <ploujo_c@epitech.net>
## 
## Started on  Tue Mar 17 03:49:40 2015 Ploujoux Christophe
## Last update Sat May 16 12:51:34 2015 Ploujoux Christophe
##

CC	=	gcc

RM      =	rm -f

NAME1   =	./generateur/gen
NAME2	=	./profondeur/solver
NAME3	=	./largeur/solver

SRC1  	=	generateur/main.c \
		generateur/queue.c \
		generateur/struct.c \
		generateur/perfect.c \
		generateur/check.c \
		basic_functions/my_strcat.c \
		basic_functions/str.c \
		basic_functions/tab.c \
		basic_functions/x_fonction.c

SRC2	=	profondeur/profondeur.c \
		profondeur/error.c \
		profondeur/struct.c \
		profondeur/aff.c \
		basic_functions/get_next_line.c \
		basic_functions/x_fonction.c \
		basic_functions/tab.c \
		basic_functions/str.c

SRC3	=	largeur/largeur.c \
		largeur/error.c \
		largeur/struct.c \
		largeur/aff.c \
		largeur/main.c \
		basic_functions/get_next_line.c \
		basic_functions/x_fonction.c \
		basic_functions/tab.c \
		basic_functions/str.c

CFLAGS	+=	-W -Wall -g
CFLAGS	+=	-Wextra -pedantic
CFLAGS	+=	-I./include

OBJ1	=	$(SRC1:.c=.o)
OBJ2	=	$(SRC2:.c=.o)
OBJ3	=	$(SRC3:.c=.o)

all	:	$(NAME1) $(NAME2) $(NAME3)

$(NAME1):	$(OBJ1)
		$(CC) $(OBJ1) -o $(NAME1)

$(NAME2):	$(OBJ2)
		$(CC) $(OBJ2) -o $(NAME2)

$(NAME3):	$(OBJ3)
		$(CC) $(OBJ3) -o $(NAME3)

clean	:
		$(RM) $(OBJ1)
		$(RM) $(OBJ2)
		$(RM) $(OBJ3)

fclean	:	clean
		$(RM) generateur/gen
		$(RM) profondeur/solver
		$(RM) largeur/solver

re	:	fclean all
