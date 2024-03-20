/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:34:00 by locharve          #+#    #+#             */
/*   Updated: 2024/03/15 16:23:52 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	main(void)
{
	char	*prompt;
	//char	*prv;
	char	*str;
	
	prompt = ft_strdup("$>");
	if (!prompt)
		return (1);
	//prv = NULL;
	str = readline(prompt);
	while (str)
	{
		//if (prv && ft_strcmp
		add_history(str);
		printf("%s", str);
		if (str[0])
			printf("\n");
		free(str);
		str = readline(prompt);
	}
	free(rl_prompt);
	
	rl_clear_history();

	free(prompt);
	free(str);
	return (0);
}
