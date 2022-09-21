/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:41:40 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/21 20:31:54 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define PIPE 3
#define WORD 4
#define REDIR 5
#define QUOTED 6
#define GENERAL 7



typedef struct s_env
{
    char    *name;
    char    *value;
    struct s_env    *next;
} t_env;

typedef struct s_list
{
    struct s_token *head;
    struct s_token *tail;
    int size;
} t_list;

typedef struct s_token
{
    char *content;
    struct s_token *next;
    int type;
} t_token;

t_env   *envir;
int	ft_strlen(const char *s);
void    sighandl(int sig);
void    printenv(void);
void    parsenv(char **env);
void	add_back(t_env **lst, t_env *new);
t_env   *new_env(char *name, char *value);
t_env	*ft_lstlast(t_env *lst);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void    builtins(char *line, char **env);
t_token *tokenize(char *line);
int ft_isspace(char c);
int	ft_isalpha(int c);
int is_redir(int c);
int is_pipe(int c);
int is_parenthesis_and(int c);
int is_special(int c);
int is_digit(int c);
int is_word(char *str);

#endif