NAME = Minishell
CC = gcc
FILES = utils/ft_strlen.c utils/ft_strncmp.c utils/ft_split.c environment.c lexer.c lexer_utils.c builtins/builtins.c \
			builtins/ft_cd.c builtins/ft_echo.c builtins/ft_env.c builtins/ft_exit.c builtins/ft_export.c \
			builtins/ft_pwd.c builtins/ft_unset.c minishell.c
OBJ = ${FILES:.c=.o}
FLAGS = -Wall -Wextra -Werror

%.o: %.c minishell.h
	$(CC) $(FLAGS) -g -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	$(CC) -lreadline $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean all
