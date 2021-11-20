##
## EPITECH PROJECT, 2021
## B-CPE-110-MAR-1-1-BSQ-thibaut.tran
## File description:
## Makefile
##

SRC	=	src/my_func.c	\
		src/load_my_tab.c	\
		src/find_bsq.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	= bsq

all	:	$(NAME)	$(SRC)

$(NAME)	:	$(OBJ)
	gcc	-c	-Wall	-g3	-Wextra	$(SRC)
	gcc	$(OBJ)	-o	$(NAME)

clean :
	rm	-f	*.o
	rm	-f	*~
	rm src/*.o

fclean :clean
	rm	-f	$(NAME)

re :	fclean	all