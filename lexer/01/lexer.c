/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:26:37 by locharve          #+#    #+#             */
/*   Updated: 2024/03/13 16:05:26 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int   is_command(char *str)
{
    if (!ft_strcmp(str, "echo"))
        return (1);
    else if (!ft_strcmp(str, "cd"))
        return (2);
    else if (!ft_strcmp(str, "pwd"))
        return (3);
    else if (!ft_strcmp(str, "export"))
        return (4);
    else if (!ft_strcmp(str, "unset"))
        return (5);
    else if (!ft_strcmp(str, "env"))
        return (6);
    else if (!ft_strcmp(str, "exit"))
        return (7);
    else
        return (0);
}

static t_token	*tokenize_alpha(char *str, int *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token)
	{
		token->str = cut_token(str, i, 0);
		token->cmd = is_command(token->str);
		if (token->cmd)
			token->type = __command;
		else
			token->type = __arg;
		token->nxt = NULL;
	}
	return (token);
}

static t_token	*tokenize_special(char *str, int *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token)
	{
		token->str = cut_token(str, i, 1);
		token->cmd = __none;
		token->type = __special;
		token->nxt = NULL;
	}
	return (token);
}

t_token	*tokenizer(char *str)
{
	t_token	*lst;
	t_token	*tmp;
	int		i;

	lst = NULL;
	i = 0;
	while (str[i])
	{
		if (is_alphanum_or_underscore(str[i])) /// ?
			tmp = tokenize_alpha(str, &i);
		else if (is_in_str(CHARSET, str[i]))
			tmp = tokenize_special(str, &i);
		else
		{
			tmp = NULL;
			i++;
		}
		if (tmp)
			lstadd_back(&lst, tmp);
	}
	return (lst);
}
