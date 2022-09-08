/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:08:41 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/08 19:10:23 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstlast(t_env *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_env   *new_env(char *name, char *value)
{
    t_env   *envi;
    
    envi = (t_env *)malloc(sizeof(t_env));
    envi->name = name;
    envi->value = value;
    envi->next = NULL;
    return (envi);
}

void	add_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (*lst != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
void    parsenv(char **env)
{
    int i;
    t_env   *node;
    char **splitted;

    i = -1;
    while (env[++i])
    {
        splitted = ft_split(env[i], '=');
        node = new_env(splitted[0], splitted[1]);
        add_back(&envir, node);

    }
}

void    printenv(void)
{
    t_env   *tmp;
    tmp = envir;

    while(tmp != NULL)
    {
        printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
}