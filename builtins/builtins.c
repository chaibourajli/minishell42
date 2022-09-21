/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:39:45 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/17 15:07:42 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    builtins(char *line, char **env)
{
    (void)env;
    
    if (!ft_strncmp(line, "pwd", ft_strlen(line)))
        ft_pwd();
	else if (!ft_strncmp(line, "exit", ft_strlen(line)))
		ft_exit();
    else if (!ft_strncmp(line, "echo", ft_strlen(line)))
		ft_echo();
	else if (!ft_strncmp(line, "env", ft_strlen(line)))
		printenv();
    else if(!ft_strncmp(line, "cd", ft_strlen(line)))
        ft_cd();
    else if(!ft_strncmp(line, "export", ft_strlen(line)))
        ft_export();
    else if(!ft_strncmp(line, "unset", ft_strlen(line)))
        ft_unset();

}