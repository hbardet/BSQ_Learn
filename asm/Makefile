##
## EPITECH PROJECT, 2024
## asm
## File description:
## Makefile
##

AS	=	nasm

SRC	=	./src/main.s\
		./src/get_size_file.s\

OBJ	=	$(SRC:.s=.o)

ASFLAGS	+=	-f elf64

NAME	=	bsq_learn

all: $(NAME)

$(NAME): $(OBJ)
	ld $(OBJ) -o $(NAME)

gdb : $(OBJ)
	ld $(OBJ) -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) ./a.out
	
re: fclean
	make all
