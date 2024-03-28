/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:56:21 by locharve          #+#    #+#             */
/*   Updated: 2024/03/28 15:56:22 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	count_words(char const *str, char *sep)
{
	int	count;
	int	i;
	int	tmp;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_in_str(sep, str[i]))
			i++;
		if (str[i] && !is_in_str(sep, str[i]))
		{
			tmp = handle_word(str, sep, &i);
			if (tmp < 0)
				return (tmp);
			else
				i += tmp;
			count++;
		}
	}
	return (count);
}

static char	*str_piece_cpy(char const *str, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		tmp[i] = str[start + i];
		i++;
	}
	return (tmp);
}

static char	*from_str_to_strs(char const *str, int *i, char *sep)
{
	char	*dst;
	int		j;
	int		tmp;

	while (str[*i] && is_in_str(sep, str[*i]))
		*i += 1;
	j = *i;
	if (str[j] && !is_in_str(sep, str[j]))
	{
		tmp = handle_word(str, sep, &j);
		if (tmp < 0)
			return (NULL);
		else
			j += tmp;
	}
	dst = str_piece_cpy(str, *i, j);
	*i = j;
	return (dst);
}

void	free_strtab(char **strtab)
{
	int	i;

	i = 0;
	if (strtab)
	{
		while (strtab[i])
		{
			free(strtab[i]);
			i++;
		}
		free(strtab);
	}
	return ;
}

char	**ft_split_mish(char const *str, char *sep)
{
	char	**dst;
	int		count;
	int		i;
	int		index;

	if (!str)
		return (NULL);
	count = count_words(str, sep);
	if (count < 0)
		return (NULL);
	dst = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	index = 0;
	while (i < count)
	{
		dst[i] = from_str_to_strs(str, &index, sep);
		if (!dst[i])
		{
			free_strtab(dst);
			return (NULL);
		}
		i++;
	}
	return (dst);
}
/*
int	main(int argc, char **argv)
{
	char	**tab;
	int		i;

	if (argc == 2)
	{
		//printf("count = %d\n", count_words(argv[1], WHITESPACES));
		tab = ft_split(argv[1], WHITESPACES);
		if (tab)
		{
			i = 0;
			while (tab[i])
			{
				printf("|%s|\n", tab[i]);
				i++;
			}
			free_strtab(tab);
		}
	}
	return (0);
}
*/
