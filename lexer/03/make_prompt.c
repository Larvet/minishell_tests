/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:17:27 by locharve          #+#    #+#             */
/*   Updated: 2024/03/25 16:22:33 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*make_prompt(void)
{
	char	*logname;
	char	*at;
	char	*s_manager;
	char	*prompt;

	logname = getenv("LOGNAME");
	logname = ft_strndup(logname, ft_strlen(logname));
	if (logname)
	{
		at = ft_strndup("@", 1);
		if (at)
		{
			s_manager = getenv("SESSION_MANAGER");
			s_manager = ft_strchr(s_manager, '/');
			s_manager = ft_strndup(s_manager, ft_strchr(s_manager, '.') - s_manager);
			if (s_manager)
			{
				prompt = ft_strjoin_va(logname, at, s_manager, NULL);
				free(s_manager);
			}
			//free(at);
		}
	}
	return (prompt);
}

int	main(void)
{
	char	*prompt;

	prompt = make_prompt();
	if (prompt)
	{
		printf("%s\n", prompt);
		free(prompt);
	}
	return (0);
}
