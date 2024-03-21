/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:27:03 by locharve          #+#    #+#             */
/*   Updated: 2024/03/21 16:48:27 by locharve         ###   ########.fr       */
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
	// else error
	*i += j;
	return (j);
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
			count_quotes(str, &i, str[i]);
			if (!str[i] || !is_in_str(WHITESPACES, str[i]))
			{
				count++;
				if (!str[i])
					break ;
			}
		}
		if (i > 0 && is_in_str(sep, str[i]) && !is_in_str(sep, str[i - 1]))
			count++;
		i++;
	}
	if (i > 0 && !is_in_str(sep, str[i - 1]))
		count++;
	return (count);
}

static char	*piece_cpy(const char *str, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc((end - start + 1) * sizeof(char));
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
	if (str[*i] == '\'' || str[*i] == '\"')
		count_quotes(str, &j, str[*i]);
	else
	{
		while (str[j] && !is_in_str(sep, str[j]))
			j++;
	}
	dst = piece_cpy(str, *i, j);
	*i = j;
	return (dst);
}

char	**ft_split(char const *str, char *sep)
{
	char	**split;
	int		nbr_str;
	int		i;
	int		index;

	if (!str)
		return (NULL);
	nbr_str = count_words(str, sep);
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