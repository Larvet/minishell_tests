/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:59:16 by locharve          #+#    #+#             */
/*   Updated: 2024/03/13 16:02:45 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lstadd_back(t_token **lst, t_token *new)
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

void	lstclear(t_token *lst)
{
	if (lst)
	{
		if (lst->nxt)
			lstclear(lst->nxt);
		free(lst->str);
		free(lst);
	}
	return ;
}
