/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:20:36 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/09 19:23:54 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtins(char *line, char **env)
{
    int i;
    
    char path[1000];
	if (!ft_strncmp(line, "pwd", ft_strlen(line)))
		printf("%s\n", getcwd(path, sizeof(path)));
	else if (!ft_strncmp(line, "env", ft_strlen(line)))
	{
        i = 0;
	    while (env[i])
	    printf("%s\n", (env[i++]));
	}
	else if (!ft_strncmp(line, "exit", ft_strlen(line)))
		exit(0);
}