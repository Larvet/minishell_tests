/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:25:53 by locharve          #+#    #+#             */
/*   Updated: 2024/03/19 17:24:15 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	is_separator(char c)
{
	if (is_space(c) || c == '<' || c == '>' || c == '|')
		return (1);
	else
		return (0);
}

static t_token	*tokenize_one(char *line, int *i)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (token)
	{
		if (line[*i] == '$')							// var
			tokenize_var(token, line, i);
		else if (line[*i] == '-')						// flag
			tokenize_flag(token, line, i);
		else if (line[*i] == '<' || line[*i] == '>')	// redir
			tokenize_redir(token, line, i);
		else if (line[*i] == '|')						// pipe
			tokenize_pipe(token, line, i);
		else if (line[*i] == '\'' || line[*i] == '\"')	// quotes / literal
			tokenize_str(token, line, i);
		else if (!is_separator(line[*i]))	// word
			tokenize_word(token, line, i);
		else
			tokenize_error(token);				// error ?
	}
	return (token);
}

t_token	*tokenizer(char *line)
{
	t_token	*lst;
	t_token	*tmp;
	int		i;

	lst = NULL;
	i = 0;
	while (line && line[i])
	{
		while (is_space(line[i]))
			i++;
		if (line[i])
		{
			tmp = tokenize_one(line, &i);
			if (tmp && tmp->type)
				lstadd_back(&lst, tmp);
			else
			{
				lstclear(lst);	// malloc error // display error
				break ;
			}
		}
	}
	return (lst);
}
