##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC 		=		src/main.c						\
					src/create_file.c				\
					src/check_file_format.c			\
					src/get_body_size.c				\
					src/write_header.c				\
					src/write_body.c				\
					src/write_instruction_byte.c	\
					src/write_code_byte.c			\
					src/verif_body.c				\
					src/find_label_size_to_jump.c	\

OBJ			=  		$(SRC:.c=.o)

CFLAGS 	+=		-Wall							\
					-Wextra							\

NAME 		=		asm

LIBMYFLAGS	= 		-I lib/my/include/my_lib.h		\
					-L .							\
					-l reworked						\

LIBRFFLAGS	=		-I lib/rf/include/rf.h			\
					-L .							\
					-l rf							\

NAME_LIBMY	=		libreworked.a

NAME_LIBRF	=		librf.a

TEST		=		unit_tests

all:	$(NAME)

$(NAME): 	$(OBJ)
	$(MAKE) -C lib/my
	$(MAKE) -C lib/rf
	mv lib/my/$(NAME_LIBMY) .
	mv lib/rf/$(NAME_LIBRF) .
	ar rc $(NAME_LIBMY) $(NAME_LIBRF) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBMYFLAGS) $(CFLAGS) $(LIBRFFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf $(NAME_LIBMY)
	rm -rf *.a
	rm -rf main.o
	make clean -C lib/my
	make clean -C lib/rf
	rm -rf */*~
	rm -rf *~
	rm -rf */*#
	rm -rf *#
## rm -rf *.cor

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TEST)*

re:	fclean all

$(TEST):	clean all
	gcc test/test.c -o $(TEST) --coverage -lcriterion $(WARNFLAGS)

test: $(TEST)
	./$(TEST)
	gcovr --exclude tests/

debug:	WARNFLAGS += -g3
debug: 	re
