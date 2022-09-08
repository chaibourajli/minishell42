/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:41:40 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/08 19:21:42 by cbourajl         ###   ########.fr       */
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

typedef struct s_cmd
{
    char *line;
    char path[1000];

}   t_cmd;

typedef struct s_env {
    char    *name;
    char    *value;
    struct s_env    *next;
} t_env;

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

#endif