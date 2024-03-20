/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:26:47 by locharve          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:05 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	substitute_var(t_token *token)
{
	char	*tmp;

	tmp = getenv(token->str);
	free(token->str);
	if (tmp)
	{
		token->str = ft_strndup(tmp, ft_strlen(tmp));
		if (!token->str)
			token->err = __malloc;
	}
	else
		token->str = ft_strndup("", 0);
	return ;
}
/*
int	main(int argc, char **argv)
{
	t_token	token;

	if (argc == 2)
	{
		token.str = ft_strndup(argv[1], ft_strlen(argv[1]));
		token.type = __var;
		token.err = 0;
		token.nxt = NULL;
		if (token.str)
		{
			substitute_var(&token);
			printf("%s\n", token.str);
			free(token.str);
		}
	}
	return (0);
}
*/
