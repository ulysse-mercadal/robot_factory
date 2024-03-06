##
## EPITECH PROJECT, 2023
## lib rf
## File description:
## lib for robot factory project
##

SRC		=	src/my_memcpy.c				\
			src/reverse_int_bit.c		\
			src/reverse_int_16_bit.c	\
			src/my_contextual_atoi.c	\
			src/is_a_nbr.c				\

NAME	=	librf.a

CFLAGS 	=	-Wall						\
			-Wextra

OBJ		= 	$(SRC:.c=.o)				\

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

fclean:	clean
	rm -f $(NAME)

clean:
		rm -f $(OBJ)

re:	fclean all
