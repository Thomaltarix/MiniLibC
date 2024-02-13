##
## EPITECH PROJECT, 2024
## MiniLibC
## File description:
## Makefile
##

## Variables
ASM	= nasm

NAME	= libasm.so

TEST_NAME = unit_tests

## Sources
SRC	=	src/strlen.asm		\
		src/strchr.asm		\
		src/strrchr.asm		\
		src/memset.asm		\
		src/memcpy.asm		\
		src/strcmp.asm		\
		src/memmove.asm		\
		src/strncmp.asm		\
		src/strcasecmp.asm	\

OBJ	= $(SRC:.asm=.o)


## Flags
ASMFLAGS	= -f elf64


## Tests
TEST_SRC	=	tests/tests_strlen.c	\
				tests/tests_strchr.c	\
				tests/tests_strrchr.c	\
				tests/tests_memset.c	\
				tests/tests_memcpy.c	\
				tests/tests_strcmp.c	\

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
		ld -shared -o $(NAME) $(OBJ)

%.o:	%.asm
		$(ASM) $(ASMFLAGS) $< -o $@

clean:
		rm -f $(OBJ)
		rm -f *.gcno
		rm -f *.gcda

fclean:	clean
		rm -f $(NAME)
		rm -f $(TEST_NAME)

re:	fclean all

tests_run: all
		gcc -o $(TEST_NAME) $(TEST_SRC) -lcriterion --coverage
		./$(TEST_NAME)
