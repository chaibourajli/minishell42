/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:39:49 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/14 19:14:40 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>


t_token *new_token(char *content, int type)
{
    t_token *token;

    token = (t_token *)malloc(sizeof(t_token *));
    token->content = malloc (strlen(content) + 1);
    int i = 0;
    while (content[i])
    {
        token->content[i] = content[i];
        i++;
    }
    token->content[i] = '\0';
    token->type = type;
    token->next = NULL;
    return (token);
}
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
        {
            add_back_tok(&tokens, splitted[i], WORD);
            printf("%s\n", tokens->content);
        }
        // else if (ft_strlen(splitted[i]) == 1)
        // {
        //     if (is_pipe(splitted[i][0]))
        //     {
        //         token = new_token("|", PIPE);
        //         add_back_tok(&tokens, token);
        //     }
        //     else if (is_redir(splitted[i][0]))
        //     {
        //         token = new_token(&splitted[i][0], REDIR);
        //         add_back_tok(&tokens, token);
        //     }
        //     else if (is_parenthesis_and(splitted[i][0]))
        //     {
        //         printf("syntax error\n");
        //         return (0);
        //     }
        // }
        i++;
    }
    return (tokens);
}

void    printoken(t_token *tokens)
{
    t_token *tmp;
    
    tmp = tokens;
    while (tmp != NULL)
    {
        printf("this is a %s that is a %d\n", tmp->content, tmp->type);
        tmp = tmp->next;
    }
}

int main()
{
    t_token *tokens;
    
    tokens = lexer("dh eh efbel  eel");
    printoken(tokens);
}