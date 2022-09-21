/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:39:49 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/21 21:39:51 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*last_token(t_token *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_token *new_token(char *content, int type)
{
    t_token *new;

    new = (t_token *)malloc(sizeof(t_token *));
    new->content = content;
    new->type = type;
    new->next = NULL;
    return (new);
}

void	add_back_tok(t_token **lst, char *content, int type)
{
	t_token	*last;
    t_token *new;
    
    new = new_token(content, type);
	if (*lst != NULL)
	{
		last = last_token(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_token *lexer(char *line)
{
    char **splitted;
    t_token *tokens;
    int i;

    i = 0;
    splitted = ft_split(line, ' ');
    while (splitted[i])
    {
        if (is_word(splitted[i]))
            add_back_tok(&tokens, splitted[i], WORD);
        else if (ft_strlen(splitted[i]) == 1)
        {
            if (is_redir(splitted[i][0]))
                add_back_tok(&tokens, splitted[i], REDIR);
            else if (is_pipe(splitted[i][0]))
                add_back_tok(&tokens, splitted[i], PIPE);
        }
        i++;
    }
    return (tokens);
}

void    printoken(t_token *tokens)
{
    t_token *tmp;

    tmp = tokens;
    while (tmp)
    {
        printf("this is a %s that is a %d\n", tmp->content, tmp->type);
        tmp = tmp->next;
    }
}
