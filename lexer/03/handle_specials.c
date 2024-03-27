#include "lexer.h"

static long long	ft_atoll(char const *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (is_in_str(WHITESPACES, str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_digit(str[i]))
	{
		result = str[i] - 48 + result * 10;
		if (result > 2147483647)
			return (result);
		i++;
	}
	return (result * sign);
}

int	handle_quotes(char const *str, char q)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != q)
		i++;
	if (!str[i])
	{
		if (q == '\'')
			print_error("Unclosed quotes.\n");
		else if (q == '\"')
			print_error("Unclosed double quotes.\n");
		return (-i);
	}
	return (i + 1);
}

int	handle_redirections(char const *str)
{
	int	i;

	i = 1;
	if (str[i] == '<' || str[i] == '>')
		i++;
	return (i);
}

int	handle_specials(char const *str)
{
	if (str[0] == '\'' || str[0] == '\"')
		return (handle_quotes(str, str[0]));
	else if (str[0] == '<' || str[0] == '>')
		return (handle_redirections(str));
	else if (str[0] == '|')
		return (1);
	return (-1);
}

int	handle_fd_redir(char const *str)
{
	long long	check;
	int			i;
	int			j;

	check = ft_atoll(str);
	if (check < 0 || check > 1023)
	{
		print_error(": Bad file descriptor\n"); //////////
		return (-1);
	}
	i = 0;
	while (is_digit(str[i]))
		i++;
	j = 0;
	if (j < 2 && (str[i + j] == '<' || str[i + j] == '>'))
		j++;
	i += j;	//////// reconnaissance de &| ?
	return (i);
}

int	handle_word(char const *str, char *sep, int *i)
{
	int	j;

	j = 0;
	if (is_in_str(ALL_SPECIAL, str[*i]))
		j = handle_specials(&str[*i]);
	else if (is_digit(str[*i]) && (*i == 0 || is_in_str(sep, str[*i - 1])))
		j = handle_fd_redir(&str[*i]);
	else
	{
		while (str[*i + j] && !is_in_str(sep, str[*i + j])
				&& !is_in_str(ALL_SPECIAL, str[*i + j]))
			j++;
	}
	return (j);
}
