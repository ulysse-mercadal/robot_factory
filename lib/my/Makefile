##
## EPITECH PROJECT, 2023
## lib reworked
## File description:
## lib Makefile
##

SRC		=	src/my_putchar.c			\
			src/my_putstr.c				\
			src/my_putstrerr.c			\
			src/my_putnbr.c				\
			src/my_putfloat.c			\
			src/my_atoi.c				\
			src/my_atof.c				\
			src/my_strncmp.c			\
			src/my_strstr.c				\
			src/my_revstr.c				\
			src/my_str_split.c			\
			src/my_pow.c				\
			src/my_strdup.c				\
			src/my_strlen.c				\
			src/my_intlen.c				\
			src/my_atoi_enhanced.c		\
			src/my_atof_enhanced.c		\
			src/my_strcat.c				\
			src/my_strcpy.c				\
			src/my_strcmp.c				\
			src/my_cleanstr.c 			\
			src/my_split.c				\
			src/my_strncat.c			\
			src/my_get_file_content.c	\

NAME	=	libreworked.a

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
