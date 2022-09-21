/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:45:52 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/17 15:07:08 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void    sighandl(int sig)
{
    signal(sig, SIG_IGN);
    exit(0);
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    char *line;
    
    parsenv(env); 
    while (1)
    {
	    printf("\033[1;32m");
        line = readline("Minishell$ > \033[0m ");
        builtins(line, env);
        add_history(line);
        rl_on_new_line();
    }
}
