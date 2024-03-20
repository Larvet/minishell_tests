/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:24:59 by locharve          #+#    #+#             */
/*   Updated: 2024/03/13 17:11:52 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char	*ft_strndup(char *src, int n)
{
	char	*dst;
	int		i;

	dst = malloc((n + 1) * sizeof(char));
	if (dst)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

static char	*alphanum_cut(char *str, int *i)
{
	char	*dst;
	int		j;

	j = 0;
	//while (str[*i + j] && !is_space(str[*i + j])
	//		&& !is_in_str(CHARSET, str[*i + j]))
	while (str[*i + j] && isalphanum_or_underscore(str[*i + j]))
		j++;
	dst = ft_strndup(&str[*i], j);
	*i += j;
	return (dst);
}

char	*cut_token(char *str, int *i, int mode)
{
	char	*res;

	if (mode == 0)
		res = alphanum_cut(str, i);
	else
		res = NULL;
	return (res);
}
