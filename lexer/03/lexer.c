/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:53:47 by locharve          #+#    #+#             */
/*   Updated: 2024/03/20 16:19:18 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_command	*chunk_one_cmd(char *line, int *i)
{
	t_command	*dst;
	char		*tmp;
	int			j;

	dst = ft_calloc(1, sizeof(t_command));
	if (dst)
	{
		j = 0;
		while (line[*i + j] && line[*i + j] != '|')
			j++;
		tmp = ft_strndup(line, j);
		if (tmp)
			dst->token = quotes_split(tmp, WHITESPACES);
		else
			dst->err = __malloc;
		free(tmp);
		*i += j;
	}
	return (dst);
}

t_command	*lexer(char *line)
{
	t_command	*lst;
	t_command	*tmp;
	int			i;

	lst = NULL;
	i = 0;
	while (line && line[i])
	{
		while (is_space(line[i]))
			i++;
		if (line[i])
		{
			tmp = chunk_one_cmd(line, &i);
			if (tmp)
				lstadd_back(&lst, tmp);
			else
			{
				lstclear(lst); // print error malloc
				break ;
			}
		}
	}
	return (lst);
}
