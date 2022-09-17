/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:42:14 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/17 14:39:58 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    printenv()
{
    t_env   *tmp;
    tmp =  envir;

    while(tmp != NULL)
    {
        printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
}
