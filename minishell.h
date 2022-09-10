/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:41:40 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/10 18:50:14 by cbourajl         ###   ########.fr       */
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

#define QUOTED 6
#define GENERAL 7

#define PIPE 3
#define WORD 4
#define REDIRIN 8
#define REDIROUT 9


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
    int len;
    struct s_token *next;
    struct s_token *prev;
    int type;
    int state;
} t_token;

t_env   *envir;
size_t	ft_strlen(const char *s);
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

#endif