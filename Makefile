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
SRC	= src/tmp.asm			\

OBJ	= $(SRC:.asm=.o)


## Flags
ASMFLAGS	= -f elf64


## Tests
TEST_SRC	= tests/tmp.c		\

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
		ld -shared -o $(NAME) $(OBJ)

%.o:	%.asm
		$(ASM) $(ASMFLAGS) $(SRC)

clean:
		rm -f $(OBJ)
		rm -f *.gcno
		rm -f *.gcda

fclean:	clean
		rm -f $(NAME)
		rm -f $(TEST_NAME)

re:	fclean all

tests_run: fclean
		gcc -o $(TEST_NAME) $(TEST_SRC) -lcriterion

test:	tests_run
		./$(TEST_NAME)
