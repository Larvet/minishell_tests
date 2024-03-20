#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_his
{
	char			*str;
	struct s_his	*nxt;
}	t_his;

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static char	*without_whitespaces(char *str)
{
	int		i;

	i = 0;
	while (str[i] && is_whitespace(str[i]))
		i++;
	if (!str[i])
		return (NULL);
	else
		return (&str[i]);
}

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

	if (!src)
		return (NULL);
	dst = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dst)
	{
		i = 0;
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	is_in_history(t_his *his, char *str)
{
	t_his	*head;
	int		r;

	head = his;
	while (his && ft_strcmp(his->str, str))
		his = his->nxt;
	if (!his)
		r = 0;
	else
		r = 1;
	his = head;
	return (r);
}

static void	lstadd_back(t_his **lst, t_his *new)
{
	if (lst)
	{
		if (*lst)
			lstadd_back(&(*lst)->nxt, new);
		else
			*lst = new;
	}
	return ;
}

static void	free_all(t_his *his)
{
	if (his)
	{
		if (his->nxt)
			free_all(his->nxt);
		if (his->str)
			free(his->str);
		free(his);
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{
	t_his	*his;
	t_his	*tmp;
	char	*str;

	(void) argc;
	(void) argv;
	(void) env;
	if (argc >= 2)
	{
		his = NULL;
		str = readline("$> ");
		while (str)
		{
			tmp = malloc(sizeof(t_his));
			if (!tmp)
			{
				free_all(his);
				return (0);
			}
			if (str)
				tmp->str = ft_strdup(without_whitespaces(str));
			if ( !tmp->str)
			{
				free_all(his);
				return (0);
			}
			if (!is_in_history(his, tmp->str))
			{
				add_history(str);
				lstadd_back(&his, tmp);
			}
			else
			{
				free(tmp->str);
				free(tmp);
			}
			printf("%s\n", str);
			str = readline("$> ");
		}
		free_all(his);
	}
	return (0);
}
