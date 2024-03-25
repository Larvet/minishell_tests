#include "lexer.h"

#define ALL_SPECIAL "\'\"<>|"
/*
static int	count_words(char *str, char *sep)
{
	int	count;
	int	i;
	int	tmp;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_in_str(ALL_SPECIAL, str[i]))
		{
			if (i > 0 && !is_in_str(ALL_SPECIAL, str[i]))
				count++;
			tmp = handle_specials(&str[i], &count);
			if (tmp < 0)
				return (tmp);
			i += tmp;
		}
		if (i > 0 && ((is_in_str(sep, str[i])
				&& !is_in_str(sep, str[i - 1]))
				|| (!is_in_str(sep, str[i])
				&& is_in_str(ALL_SPECIAL, str[i - 1]))))
		{
			count++;
		//	i++;
		}
		//else
			i++;
		printf("count = %d\tc = %c\t= %d\n", count, str[i - 1], i - 1);
	}
	if (i > 0 && !is_in_str(sep, str[i - 1]))
		count++;
	return (count);
}
*/
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
