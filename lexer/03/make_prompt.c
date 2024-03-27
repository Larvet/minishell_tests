#include "lexer.h"

#include <readline/readline.h>

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

int	main(void)
{
	char	*prompt = make_prompt();
	char	*str = readline(prompt);

	while (str)
	{
		free(str);
		str = readline(prompt);
	}
	// printf("%s\n", str);
	// free(str);
	return (0);
}
