NAME = Minishell
CC = gcc
FILES = main.c
OBJ = ${FILES:.c=.o}
INCLUDESS = -I /goinfre/cbourajl/.brew/opt/readline/include
LIBRARIESS = -L /goinfre/cbourajl/.brew/opt/readline/lib -lreadline
FLAGS = -Wall -Wextra -Werror
%.o: %.c minishell.h
	$(CC) $(FLAGS) -c $< ${INCLUDESS} -o $@

all: ${NAME}

${NAME}: ${OBJ}
	$(CC) ${LIBRARIESS} $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean all
