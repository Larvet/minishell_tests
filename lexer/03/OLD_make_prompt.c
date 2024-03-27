/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:17:27 by locharve          #+#    #+#             */
/*   Updated: 2024/03/26 17:41:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	**init_colors(char **str)
{
	str[0] = ft_strndup(); // blanc
	str[1] = ft_strndup(); // vert
	str[2] = ft_strndup(); // bleu ?
}

char	*make_prompt(void)
{
	char	*logname;
	char	*at;
	char	*s_manager;
	char	*space;
	char	*pwd;
	char	*prompt;
	char	*end;

	char	*color[3];

	// colors
	// color0 logname at session_m space color1 pwd color2 end color3(blanc)

	logname = getenv("LOGNAME");
	logname = ft_strndup(logname, ft_strlen(logname));
	if (!logname)
		return (NULL);
	at = ft_strndup("@", 1);
	if (!at)
	{
		free(logname);
		return (NULL);
	}
	s_manager = getenv("SESSION_MANAGER");
	s_manager = ft_strchr(s_manager, '/');
	s_manager = ft_strndup(s_manager,  ft_strchr(s_manager, '.') - s_manager);
	if (!s_manager)
	{
		free(logname);
		free(at);
		return (NULL);
	}
	space = ft_strndup(" ", 1);
	if (!space)
	{
		// free all
		return (NULL);
	}
	pwd = ft_strrchr(getenv("PWD"), '/');
	pwd = ft_strndup(pwd, ft_strlen(pwd));
	if (!pwd)
	{
		// free all
		return (NULL);
	}
	end = ft_strndup(" $> ", 4);
	if (!end)
	{
		// free all
		return (NULL);
	}
	prompt = ft_strjoin_va(logname, at, s_manager, space, pwd, end, NULL); // error handling
	//free(s_manager);
	
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
