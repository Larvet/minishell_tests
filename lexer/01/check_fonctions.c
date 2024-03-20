/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:05:45 by locharve          #+#    #+#             */
/*   Updated: 2024/03/13 17:20:33 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_alphanum_or_underscore(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
			|| (c >= 48 && c <= 57) || c == 95)
		return (1);
	else
		return (0);
}

int is_space(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    else
        return (0);
}
/*
int is_lowercase(char c)
{
    if (c >= 97 && c <= 122)
        return (1);
    else
        return (0);
}
*/
int is_in_str(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && c != str[i])
        i++;
    if (!str[i])
        return (0);
    else
        return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
