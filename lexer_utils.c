/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 03:21:59 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/14 16:15:06 by cbourajl         ###   ########.fr       */
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

int is_redir(int c)
{
    if (c == '<' || c == '>')
        return (1);
    return (0);
}

int is_pipe(int c)
{
    if (c == '|')
        return (1);
    return (0);
}

int is_parenthesis_and(int c)
{
    if (c == '{' || c == '&' || c == ';' || c == '}' || c == '(' || c == ')')
        return (1);
    return (0);
}
int is_special(int c)
{
    if (!is_pipe(c) && !is_redir(c) && !is_parenthesis_and(c))
        return (1); 
    return (0);
}

int is_digit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_word(char *str)
{
    int i;

    i = 0;
    while (ft_isalpha(str[i]) || is_digit(str[i]))
        i++;
    if (i == ft_strlen(str))
        return (1);
    else
        return (0);
}
