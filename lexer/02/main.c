/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:17:05 by locharve          #+#    #+#             */
/*   Updated: 2024/03/19 15:44:47 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	print_tokenlst(t_token *lst)
{
	if (lst)
	{
		printf("%s\t", lst->str);
		if (lst->type == __error)
			printf("error\t");
		else if (lst->type == __word)
			printf("word\t");
		else if (lst->type == __quoted)
			printf("quoted\t");
		else if (lst->type == __dquoted)
			printf("dquoted\t");
		else if (lst->type == __flag)
			printf("flag\t");
		else if (lst->type == __var)
			printf("var\t");
		else if (lst->type == __redir_l)
			printf("<\t");
		else if (lst->type == __redir_ll)
			printf("<<\t");
		else if (lst->type == __redir_r)
			printf(">\t");
		else if (lst->type == __redir_rr)
			printf(">>\t");
		else if (lst->type == __pipe)
			printf("|\t");

		if (lst->err == __no_err)
			printf("no_err\n");
		else if (lst->err == __malloc)
			printf("malloc\n");
		else if (lst->err == __open_quote)
			printf("open_quote\n");
		else if (lst->err == __open_dquote)
			printf("open_dquote\n");
		else if (lst->err == __invalid)
			printf("invalid\n");

		print_tokenlst(lst->nxt);
	}
	return ;
}

int	main(void)
{
	t_token	*lst;
	char	*line;

	line = readline("$> ");
	while (line)
	{
		add_history(line);
		lst = tokenizer(line);
		if (lst)
		{
			print_tokenlst(lst);
			lstclear(lst);
		}
		free(line);
		line = readline("$> ");
	}
	clear_history();
	return (0);
}
