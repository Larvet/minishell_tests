#include "lexer.h"

int	handle_quotes(char *str, int *count, char q)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != q)
		i++;
	if (!str[i])
	{
		if (q == '\'')
			print_error("ERROR\tUnclosed quotes.\n");
		else if (q == '\"')
			print_error("ERROR\tUnclosed double quotes.\n");
		return (-i);
	}
	*count += 1;
	return (i);
}

int	handle_redirections(char *str, int *count, char r)
{
	// cas particulier : <>
	int	i;

	i = 1;
	while (is_in_str(WHITESPACES, str[i]))
		i++;
	if (str[i] == '<' || str[i] == '>')
	{
		if (i > 1 || (r == '>' && str[i] == '<'))
		{
			print_error("-bash: syntax error near unexpected token '");
			write(2, &str[i], 1);
			print_error("'\n");
			return (-i);
		}
		else if (str[i] == r)
			i++;
	}


	if (r == '<')
	{
		if (str[i] == '>')
			print_error("-bash: syntax error near unexpected token '>'\n");
		else if (str[i] == r)
		{
			i++;
			while (is_in_str(WHITESPACES, str[i]))
				i++;
			while (!is_in_str(WHITESPACES, str[i])
					&& !is_in_str(ALL_SPECIAL, str[i]))
				i++;
		}
	}
	else if (q
	return (i);
}

int	handle_specials(char *str, int *count)
{
	if (str[0] == '\'' || str[0] == '\"')
		return (handle_quotes(str, count, str[i]));
	else if (str[0] == '<' || str[0] == '>')
		return (handle_redirections(str, count, str[i]));
	else if (str[0] == '|')
	{
		*count += 1;
		return (1);
	}
	return (-1);
}
