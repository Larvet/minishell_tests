/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:45 by locharve          #+#    #+#             */
/*   Updated: 2024/03/22 16:18:04 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char	*ft_strcat_m(char *s1, char *s2)
{
	char	*dst;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = ft_calloc(len, sizeof(char));
	if (dst)
	{
		i = 0;
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			dst[i + j] = s2[j];
			j++;
		}
	}
	return (dst);
}

void	print_error(char *str)
{
	char	*err;

	err = ft_strcat_m("ERROR\t", str);
	if (err)
		write(2, err, ft_strlen(err));
	free(err);
	return ;
}
