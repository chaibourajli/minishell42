/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 03:21:59 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/10 18:17:13 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
        return (1);
    return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

t_token *new_token(char *content, int len, int type, int state)
{
    t_token *token;

    token = (t_token *)malloc(sizeof(t_token));
    token->content = content;
    token->len = len;
    token->type = type;
    token->state = state;
    return (token);
}

t_token *tokenize(char *line)
{
    t_token *token;
    int i;
    int j;
    int k;
    char *quotes;

    i = -1;
    while (line[++i])
    {
        if (line[i] == '"')
        {
            j = i + 1;
            k = -1;
            while (line [j++] != '"')
                quotes[++k] = line[j];
            if (j == ft_strlen(line) && line[ft_strlen] != '"')
                return( printf("error"), 0);
            return (new_token(quotes, ft_strlen(quotes), WORD, QUOTED));
        }
        else if (line[i] == '|')
            return (new_token("|", 1, PIPE, GENERAL));
        else if (line[i] == '\' || line[i] == ';')
            continue;
        else if (line[i] == '<')
            return(new_token("<", 1, REDIRIN, GENERAL));
        else if (line[i] == '>')
            return (new_token(">", 1, REDIROUT, GENERAL));
    }
    free (token);
}