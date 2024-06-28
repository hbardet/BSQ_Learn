##
## EPITECH PROJECT, 2022
## info_file
## File description:
## makefile for the cat dunction
##

SRC	=	./src/main.c\
		./src/init_bsq.c\
		./src/load_bsq.c\
		./src/resolve_bsq.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq_learn

CFLAGS +=	-Wextra -Wall -W -I./include -O2

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f vgcore.*

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
