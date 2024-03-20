/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:46:30 by locharve          #+#    #+#             */
/*   Updated: 2024/03/07 16:36:14 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// execve

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char *ft_strcat_m(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
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
	dst[i + j] = '\0';
	return (dst);
}
/*
static char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	dst = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
*/
int	main(int argc, char **argv, char **env)
{
	char	*cmd;

	if (argc >= 2)
	{
		if (ft_strcmp(argv[1], "cd"))
		{
			cmd = ft_strcat_m("/bin/", argv[1]);
			execve(cmd, &argv[2], env);
		}
		else
		{
			//cmd = ft_strdup(argv[2]);
			execve(argv[2], &argv[3], env);
		}
//		if (cmd)
//			execve(cmd, &argv[1], env);
		if (cmd)
			free(cmd);
	}
	return (0);
}
