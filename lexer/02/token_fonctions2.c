/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_fonctions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:56:12 by locharve          #+#    #+#             */
/*   Updated: 2024/03/19 16:35:21 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *src, int n)
{
	char	*dst;
	int		i;

	dst = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (dst)
	{
		i = 0;
		while (src[i] && i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}

void	tokenize_str(t_token *token, char *line, int *i)
{
	int	j;

	j = 1;
	if (line[*i] == '\'')
		token->type = __quoted;
	else if (line[*i] == '\"')
		token->type = __dquoted;
	else
		token->type = __error;
	while (line[*i + j] && line[*i + j] != line[*i])
		j++;
	if (!line[*i + j])
		token->err = (int)token->type;
	token->str = ft_strndup(&line[*i], j);
	if (!token->str)
	{
		token->type = __error;
		token->err = __malloc;
	}
	*i += j;
	return ;
}

void	tokenize_word(t_token *token, char *line, int *i)
{
	int	j;

	j = 1;
	while (line[*i + j] && !is_separator(line[*i + j]))
		j++;
	token->str = ft_strndup(&line[*i], j);
	if (token->str)
		token->type = __word;
	else
	{
		token->type = __error;
		token->err = __malloc;
	}
	*i += j;
	return ;
}

void	tokenize_error(t_token *token)
{
	token->str = NULL;
	token->type = __error;
	token->err = __invalid;
	return ;
}
