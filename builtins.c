/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:20:36 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/14 19:18:08 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtins(char *line, char **env)
{
    int i;
    
    char path[1000];
	if (!ft_strncmp(line, "pwd", ft_strlen(line)))
		printf("%s\n", getcwd(path, sizeof(path)))
	else if (!ft_strncmp(line, "exit", ft_strlen(line)))
		exit(0);
	else if (!ft_strncmp(line, "env", ft_strlen(line)))
		printenv();
}