##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN		=	main.c

SRC_NO_TEST	=	src/my_sokoban.c		\
				src/draw_map.c

SRC_TEST	=	src/get_map.c			\
				src/free_map.c			\
				src/error_handling.c	\
				src/valid_characters.c	\
				src/find_player.c		\
				src/find_boxes.c		\
				src/find_hole.c			\
				src/move_player.c

SRC			=	$(SRC_NO_TEST) $(SRC_TEST)

CFLAGS		=	-I./include/ -Wall -Wextra

OBJ			=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME		=	my_sokoban

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -lncurses
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC_TEST) tests/*.c -L./lib -lmy -lncurses $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) -L./lib -lmy -lncurses

clean:
	rm -f $(OBJ)
	rm -f unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
