##
## EPITECH PROJECT, 2024
## go
## File description:
## Makefile
##

NAME = bsq_learn

$(NAME):
	go build -C ./src -o $(NAME)
	mv ./src/$(NAME) ./

all: $(NAME)

clean:
	go clean

fclean: clean
	rm $(NAME) -f

re: fclean all
