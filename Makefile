NAME = Minishell
CC = gcc
FILES = main.c
OBJ = ${FILES:.c=.o}
INCLUDES = -I /goinfre/cbourajl/.brew/opt/readline/include
LIBRARIES = -L /goinfre/cbourajl/.brew/opt/readline/lib -lreadline
FLAGS = -Wall -Wextra -Werror

%.o: %.c minishell.h
	$(CC) $(FLAGS) -c $< ${INCLUDES} -o $@

all: ${NAME}

${NAME}: ${OBJ}
	$(CC) ${LIBRARIES} $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean all
