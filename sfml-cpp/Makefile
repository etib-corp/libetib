##
## EPITECH PROJECT, 2023
## sfml-cpp
## File description:
## Makefile
##

SRC		=	src/main.cpp
NAME	=	main
CXXFLAGS=	-I./include -L./build -lsfmlcpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: lib
	g++ -o $(NAME) $(SRC) $(CXXFLAGS)

lib:
	mkdir -p build
	cd build && cmake .. && make

debug: lib
	g++ -o $(NAME) $(SRC) $(CXXFLAGS) -g3 -ggdb

fclean:
	rm -fr build
	rm -fr $(NAME)

re: fclean all