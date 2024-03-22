/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:27:03 by locharve          #+#    #+#             */
/*   Updated: 2024/03/22 17:11:32 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	count_quotes(char const *str, int *i, char q)
{
	int	j;

	j = 1;
	while (str[*i + j] && str[*i + j] != q)
		j++;
	if (str[*i + j])
		j++;
	else
	{
		if (q == '\'')
			print_error("Unclosed quotes.\n");
		else if (q == '\"')
			print_error("Unclosed double quotes.\n");
		return (0);
	}
	*i += j;
	return (j);
}

static int	handle_sepchars(char const *str, int *i)
{
	if (str[*i] == '<')
	{
		*i += 1;
		if (str[*i] == '<')
			*i += 1;
	}
	else if (str[*i] == '>')
	{
		*i += 1;
		if (str[*i] == '>')
			*i += 1;
	}
	else if (str[*i] == '|')
		*i += 1;
	return (1);
}

static int	count_words(char const *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (!count_quotes(str, &i, str[i]))
				return (-1);
			if (!str[i])
				break ;
/*			if ((!str[i] && !is_in_str(sep, str[i - 1]))
					|| !is_in_str(sep, str[i]))
			{
				count++;
				if (!str[i])
					break ;
			}
*/		}
		if (is_in_str(SEPCHARS, str[i]))
			 count += handle_sepchars(str, &i);
		else if (i > 0 && is_in_str(sep, str[i]) && !is_in_str(sep, str[i - 1]))
			count++;
		i++;
	}
	if (i > 0 && !is_in_str(sep, str[i - 1]))
		count++;
	//printf("count words = %d\n", count); /////////////
	return (count);
}

static char	*piece_cpy(const char *str, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc((end - start + 1) * sizeof(char));
	printf("len = %d\n", end - start); ///////////
	if (!tmp)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		tmp[i] = str[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*cut_str(const char *str, int *i, char *sep)
{
	char	*dst;
	int		j;

	while (str[*i] && is_in_str(sep, str[*i]))
		*i += 1;
	j = *i;
	if ((str[*i] == '\'' || str[*i] == '\"') 
			&& !count_quotes(str, &j, str[*i]))
		return (NULL);
	else if (is_in_str(SEPCHARS, str[*i]))
		handle_sepchars(str, &j);
	else
	{
		while (str[j] && !is_in_str(SEPARATORS, str[j]))
			j++;
	}
	dst = piece_cpy(str, *i, j);
	*i = j;
	return (dst);
}

char	**quotes_split(char const *str, char *sep)
{
	char	**split;
	int		nbr_str;
	int		i;
	int		index;

	if (!str)
		return (NULL);
	nbr_str = count_words(str, sep);
	if (nbr_str < 0)
		return (NULL);
	split = (char **)malloc((nbr_str + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (i < nbr_str)
	{
		split[i] = cut_str(str, &index, sep);
		if (!split[i])
		{
			free_all(split);
			break ;
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
int	main(int argc, char **argv)
{
	char	**split;
	int		i;

	if (argc == 2)
	{
		split = ft_split(argv[1], SEPARATORS);
		if (split)
		{
			i = 0;
			while (split[i])
			{
				printf("|%s|\n", split[i]);
				i++;
			}
			free_all(split);
		}
	}
	return (0);
}
*/
