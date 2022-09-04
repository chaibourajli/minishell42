NAME = Minishell
CC = gcc
FILES = main.c utils/ft_strlen.c utils/ft_strncmp.c
OBJ = ${FILES:.c=.o}
FLAGS = -Wall -Wextra -Werror

%.o: %.c minishell.h
	$(CC) $(FLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	$(CC) -lreadline $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean all
