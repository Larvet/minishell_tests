/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_fonctions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:56:01 by locharve          #+#    #+#             */
/*   Updated: 2024/03/19 17:24:22 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_type	is_flag_or_word(char *str)
{
	int	i;

	i = 1;
	while (str[i] && (str[i] == 'n' || str[i] == 'e' || str[i] == 'E'))
		i++;
	if (!str[i])
		return (__flag);
	else
		return (__word);
}

void	tokenize_var(t_token *token, char *line, int *i)
{
	int	j;

	j = 1;
	while (line[*i + j] && !is_separator(line[*i + j]))		// ?
		j++;
	token->str = ft_strndup(&line[*i], j);
	if (token->str)
	{
		if (j > 1)
			token->type = __var;
		else
			token->type = __word;			//
	}
	else
	{
		token->type = __error;
		token->err = __malloc;
	}
	*i += j;
	return ;
}

void	tokenize_flag(t_token *token, char *line, int *i)
{
	int	j;

	j = 1;
	while (line[*i + j] && !is_separator(line[*i + j]))
		j++;
	token->str = ft_strndup(&line[*i], j);
	if (token->str)
	{
		if (j > 1) ///////////
			token->type = is_flag_or_word(token->str);
		else
			token->type = __word;			//
	}
	else
	{
		token->type = __error;
		token->err = __malloc;
	}
	*i += j;
	return ;
}

void	tokenize_redir(t_token *token, char *line, int *i)
{
	if (line[*i] == '<')
		token->type = __redir_l;
	else if (line[*i] == '>')
		token->type = __redir_r;
	if (line[*i + 1] && line[*i + 1] == line[*i])
	{
		token->str = ft_strndup(&line[*i], 2);
		if (token->str)
			token->type += 1;
		else
			token->type = __error;
		*i += 2;
	}
	else
	{
		token->str = ft_strndup(&line[*i], 1);
		if (!token->str)
		{
			token->type = __error;
			token->err = __malloc;
		}
		*i += 1;
	}
	return ;
}

void	tokenize_pipe(t_token *token, char *line, int *i)
{
	token->str = ft_strndup(&line[*i], 1);
	if (token->str)
		token->type = __pipe;
	else
	{
		token->type = __error;
		token->err = __malloc;
	}
	*i += 1;
	return ;
}
