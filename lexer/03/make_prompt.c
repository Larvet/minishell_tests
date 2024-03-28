/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:51:35 by locharve          #+#    #+#             */
/*   Updated: 2024/03/28 15:12:55 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*make_prompt(void)
{
	char	*session_m;
	char	*result;

	session_m = getenv("SESSION_MANAGER");
	session_m = ft_strchr(session_m, '/');
	session_m = ft_strndup(session_m, ft_strchr(session_m, '.') - session_m);
	if (!session_m)
		return (NULL);
	result = ft_strjoin_va("", "\033[0;35m", getenv("LOGNAME"),
			"@", session_m, " ", "\033[0;32m",
			ft_strrchr(getenv("PWD"), '/'), "/",
			"\033[0;33m", " $> ", "\033[0;37m", NULL);
	free(session_m);
	return (result);
}
