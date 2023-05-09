FLAGS = -Wall -Wextra -Werror
CC = gcc

EXEC1 = exercicio1
EXEC2 = exercicio2
EXEC3 = exercicio4
EXEC4 = exercicio5

all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)

SRC1 = ./questao_01.c
SRC2 = ./questao_02.c
SRC3 = ./questao_04.c
SRC4 = ./questao_05.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)

$(EXEC1): $(OBJ1)
	gcc $(FLAGS) $(OBJ1) -o $(EXEC1)

$(EXEC2): $(OBJ2)
	gcc $(FLAGS) $(OBJ2) -o $(EXEC2)

$(EXEC3): $(OBJ3)
	gcc $(FLAGS) $(OBJ3) -o $(EXEC3)

$(EXEC4): $(OBJ4)
	gcc $(FLAGS) $(OBJ4) -o $(EXEC4)


clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

fclean: clean
	rm -f $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)

re: fclean all