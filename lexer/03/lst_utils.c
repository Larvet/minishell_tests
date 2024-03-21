/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:26:48 by locharve          #+#    #+#             */
/*   Updated: 2024/03/19 14:29:26 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lstadd_back(t_command **lst, t_command *new)
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			lstadd_back(&(*lst)->nxt, new);
	}
	return ;
}

void	lstclear(t_command *lst)
{
	int	i;

	if (lst)
	{
		if (lst->nxt)
			lstclear(lst->nxt);
		i = 0;
		while (lst->token && lst->token[i])
		{
			free(lst->token[i]);
			i++;
		}
		free(lst);
	}
	return ;
}
