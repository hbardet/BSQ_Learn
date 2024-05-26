##
## EPITECH PROJECT, 2022
## info_file
## File description:
## makefile for the cat dunction
##

SRC 	=	./setup_file.c \
			./read_file.c \
			./open_file.c \
			./get_line.c \
			./mem_init.c \
			./main.c \
			./get_num_fst_line.c \
			./test_sq.c \
			./setup_cordo.c \
			./bsq.c \
			./mark_bsq.c\
			./display_bsq.c \
			./select_mode.c \
			./generate_map.c

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	bsq_learn

CFLAGS +=	-Wextra -Wall -W -I./include -L./lib/my -lmy -O2

CRIFLAGS += 	--coverage -lcriterion

PATHUNIT = ../tests/unit_tests

all :	linked
	make $(NAME)

$(NAME): $(OBJ)
	 gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -rf vgcore.*

fclean:	clean
	rm -rf $(NAME)
	make -C ./lib/my fclean

linked:
	make -C ./lib/my re

.PHONY: all clean fclean re
