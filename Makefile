##
## EPITECH PROJECT, 2021
## B-CPE-110-MAR-1-1-BSQ-thibaut.tran
## File description:
## Makefile
##

SRC	=	src/load_my_tab.c	\
		src/find_bsq.c	\
		src/my_func.c	\
		src/fix_cols_rows.c	\
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