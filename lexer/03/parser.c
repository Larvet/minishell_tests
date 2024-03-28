/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:14:47 by locharve          #+#    #+#             */
/*   Updated: 2024/03/28 18:04:27 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
//#include "mish.h"

// ft_split
// remonter les erreurs dans la structt

typedef enum	e_redir
{
	__error;
	__l;
	__ll;
	__r;
	__rr;
}	t_redir;

static void	remove_quotes(char **split)
{
	char	*tmp;
	int		i;

	i = 0;
	while (split[i])
	{
		while (split[i] && split[i][0] != '\'' && split[i][0] != '\"')
			i++;
		if (split[i])
		{
			tmp = ft_strndup(&split[i][1], ft_strlen(split[i]) - 2);
			if (tmp)
			{
				printf("tmp = %s\n", tmp); //////////
				free(split[i]);
				split[i] = tmp;
			}
		}
	}
	return ;
}

static int	is_a_fd_redir(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_digit(str[i]))
		i++;
	if (!str[i] || (str[i] != '<' && str[i] != '>'))
		return (0);
	else
		return (1);
}

static void	set_io_file(t_file **io, char **tab)
{
	int	i;

	*io = ft_calloc(1, sizeof(t_file));
	if (*io)
	{
		
	}
	return ;
}

static int	separate_redirections(t_ppx_process *p, char **tab, int end)
{
	int	i;

	i = 0;
	while (tab[i] && i < end)
	{
		if (tab[i][0] == '<' || is_a_fd_redir(tab[i])) // infile
		{
			set_io_file(&p->infiles, &tab[i]);
			i++;
		}
		else if (tab[i][0] == '>' || is_a_fd_redir(tab[i])) // outfile
		{
			set_io_file(&p->outfiles, &tab[i]);
			i++;
		}
		if (tab[i] && i < end)
			i++;
	}	///////////////////////////////////
}

static void	init_process(char **tab, int end)
{
	t_ppx_process	*p;
	int				i;
	int				r_count;

	tmp = ft_calloc(1, sizeof(t_ppx_process));
	if (tmp)
	{
		r_count = separate_redirections(p, tab, end);
		i = 0;
		while (i < end)
		{
			///////////////////////////////////
		}
	}
}

static void	separate_processes(t_mish *mish, char **split)
{
	t_ppx_process	*tmp;
	int				i;
	int				j;

	tmp = NULL;
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i + j] && ft_strcmp("|", split[i + j]))
			j++;
		if (split[i + j])
		{
			tmp = init_process(&split[i], j);
			if (tmp)
				process_addback(mish->p, tmp);
		}
		i += j;
	}
	return ;
}

char	**parser(char *str)
{
	char	**split;

	split = ft_split_mish(str, WHITESPACES);
	if (split)
	{
		// if !quote_error
		remove_quotes(split);
		//separate_processes(mish, split);
	}
	return (split);
}

int	main(int argc, char **argv)
{
	char	**split;

	if (argc == 2)
	{
		split = parser(argv[1]);
		if (split)
		{
			int	i = 0;
			while (split[i])
			{
				printf("split %d = %s\n", i, split[i]);
				i++;
			}
			free_strtab(split);
		}
	}
	return (0);
}
