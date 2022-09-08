/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:45:52 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/08 19:24:50 by cbourajl         ###   ########.fr       */
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
    t_cmd   *cmd; //the return of readline is the one to be parsed.
	int i;
     
    cmd = malloc(sizeof(t_cmd));
    parsenv(env);
    while (1)
    {
	printf("\033[1;32m");
        cmd->line = readline("Minishell$ > \033[0m ");
	if (!ft_strncmp(cmd->line, "pwd", ft_strlen(cmd->line)))
		printf("%s\n", getcwd(cmd->path, sizeof(cmd->path)));
	else if (!ft_strncmp(cmd->line, "env", ft_strlen(cmd->line)))
	{
            i = 0;
	    while (env[i])
	    printf("%s ", (env[i++]));
	}
	else if (!ft_strncmp(cmd->line, "exit", ft_strlen(cmd->line)))
		exit(0);
	add_history(cmd->line);
        rl_on_new_line();
    }
    printenv();
    free (cmd);
}
