/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:25:56 by locharve          #+#    #+#             */
/*   Updated: 2024/03/26 16:04:08 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

extern char	**environ;

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat_m(char *s1, char *s2)
{
	char	*dst;
	int	i;
	int	j;

	dst = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 2, sizeof(char));
	if (dst)
	{
		i = 0;
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '/';
		i++;
		j = 0;
		while (s2[j])
		{
			dst[i + j] = s2[j];
			j++;
		}
	}
	free(s1);
	//printf("%s\n", dst); ////////////////
	return (dst);
}

void	try_cmd(char **cmd)
{
	char	**path;
	char	*str;
	pid_t	pid;
	int		i;

	str = getenv("PATH");
	if (str)
	{
		path = ft_split(str, ':');
		pid = fork();
		i = 0;
		if (pid == 0)
		{
			while (path && path[i])
			{
				path[i] = ft_strcat_m(path[i], cmd[0]);
				if (path[i] && !execve(path[i], cmd, environ))
					return ;
				i++;
			}
		}
		else
			waitpid(pid, NULL, 0);
		free_all(path);
	}
	return ; 
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		try_cmd(&argv[1]);
	}
	return (0);
}
