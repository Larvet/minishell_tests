/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:51:10 by locharve          #+#    #+#             */
/*   Updated: 2024/03/13 17:10:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	print_token_lst(t_token	*lst)
{
	if (lst)
	{
		printf("|%s|\t%d\t%d\n", lst->str, lst->cmd, lst->type);
		print_token_lst(lst->nxt);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_token	*lst;

	if (argc == 2)
	{
		lst = tokenizer(argv[1]);
		if (lst)
		{
			print_token_lst(lst);
			lstclear(lst);
		}
	}
	return (0);
}
