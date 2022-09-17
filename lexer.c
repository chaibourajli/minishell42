/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:39:49 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/17 14:34:32 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

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
        int j = 0;
        while (splitted[i][j])
        {
            if (is_parenthesis_and(splitted[i][j]))
            {
                printf("syntax error");
                return (0);
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (splitted[i])
    {
        if (is_word(splitted[i]))
            add_back_tok(&tokens, splitted[i], WORD);
        else if (ft_strlen(splitted[i]) == 1)
        {
            if (is_pipe(splitted[i][0]))
                add_back_tok(&tokens, splitted[i],  PIPE);
            else if (is_redir(splitted[i][0]))
                add_back_tok(&tokens, splitted[i], REDIR);
            else
                printf("idk what the fuck this is \n");
        }
        else
            printf("jsp\n");
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
                                   
/* int main()
{
    t_token *tokens;

    tokens = lexer("dh eh efbel | eel < < ");
    
} */