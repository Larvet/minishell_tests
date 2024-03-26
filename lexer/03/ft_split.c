#include "lexer.h"

#define ALL_SPECIAL "\'\"<>|"

static int	count_words(char *str, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_in_str(sep, str[i]))
			i++;
		if (str[i] && !is_in_str(sep, str[i]))
		{
			if (is_in_str(ALL_SPECIAL, str[i]))
				i += handle_specials(&str[i], &count); // errors -1
			else if (is_digit(str[i]) && (i == 0 || !is_in_str(sep, str[i - 1])))
				i += handle_fd_redir(&str[i], &count); // errors -1
			else
			{
				while (str[i] && !is_in_str(sep, str[i])
						&& !is_in_str(ALL_SPECIAL, str[i]))
					i++;
				count++;
			}
		}
	}
	return (count);
}

/*
char	**ft_split(char *str, char *sep)
{
	char	**dst;

}
*/
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", count_words(argv[1], WHITESPACES));
	return (0);
}
