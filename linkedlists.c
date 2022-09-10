/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:32:59 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/09 19:37:54 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



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