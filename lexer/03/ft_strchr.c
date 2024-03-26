/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:51:29 by locharve          #+#    #+#             */
/*   Updated: 2024/03/26 17:32:17 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!ft_isascii(c))
		return ((char *)s);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!ft_isascii(c))
		return ((char *)s);
	while (s[i])
		i++;
	while (i > 0 && s[i] != c)
		i--;
	if (i > 0)
		i--;
	while (i > 0 && s[i] != c)
		i--;
	return ((char *)&s[i + 1]);
}
