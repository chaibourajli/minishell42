/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:39:49 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/11 17:05:28 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *tokens;

t_token *new_token(char *content, int type)
{
    t_token *token;

    token = (t_token *)malloc(sizeof(t_token *));
    token->content = content;
    token->type = type;
    token->next = NULL;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(*s) * (len + 1));
	i = 0;
	j = 0;
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[len] = '\0';
	return (res);
}

t_token *lexer(char *line)
{
    t_token *token;
    int i;
    int origin;
    int len;
    
    len = 0;
    i = -1;
    while (line[++i])
    {
        if (is_word(line[i]))
        {
            origin = i;
            while (is_word(line[i++]))
                len++;
            new_token()
        }
    }
}