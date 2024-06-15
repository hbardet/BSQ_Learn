##
## EPITECH PROJECT, 2024
## cpp_thread
## File description:
## Makefile
##


SRC = ./main.cpp\
	  ./BSQ.cpp\
	  ./ThreadPool.cpp

OBJ =	$(SRC:.cpp=.o)

NAME =	bsq_learn

FLAGS   =	-g -std=c++20 -W -Wall -Werror -Wextra -lm -lpthread -ldl

CXXFLAGS  +=	$(FLAGS)

all:	$(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf vgcore.*

fclean:     clean
	rm -rf $(NAME)

re:     fclean all
