/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:51:06 by locharve          #+#    #+#             */
/*   Updated: 2024/03/22 17:02:22 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_command	*lexer(char *line)
{
	t_command	*lst;
	char		**split;
	int			i;

	lst = NULL;
	split = quotes_split(line, WHITESPACES);
	i = 0;
	while (split && split[i])
	{
		printf("|%s|\n", split[i]);
		i++;
	}
	if (split)
		free_all(split);
/*	while (line && line[i])
	{
		while (is_space(line[i]))
			i++;
		if (line[i])
		{
			
		}
	}
*/	return (lst);
}
