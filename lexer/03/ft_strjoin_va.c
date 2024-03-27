#include "lexer.h"
/*
static unsigned int	ft_copy_index(char *dst, char *src, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t			len_s1;
	size_t			len_s2;
	unsigned int	index;
	char			*dst;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!dst)
		return (NULL);
	index = ft_copy_index(dst, s1, 0);
	ft_copy_index(dst, s2, index);
    free(s1);
    free(s2);
	return (dst);
}

char	*ft_strjoin_va(char *str, ...)
{
	va_list	param;
	char	*dst;
	char	*tmp;

	if (!str)
		return (NULL);
	va_start(param, str);
    dst = ft_strjoin(str, va_arg(param, char *));
	if (dst)
	{
	    tmp = va_arg(param , char *);
	    while (tmp)
	    {
            tmp = ft_strndup(tmp, ft_strlen(tmp));
	    	dst = ft_strjoin(dst, tmp);
	    	if (!dst)
	    		break ;
	    	tmp = va_arg(param, char *);
	    }
	}
    va_end(param);
	return (dst);
}
*/
static size_t	len_sum(va_list param)
{
	char	*str;
	size_t	result;

	result = 0;
	str = va_arg(param, char *);
	while (str)
	{
		result += ft_strlen(str);
		str = va_arg(param, char *);
	}
	return (result);
}

static char	*ft_strcat_va(char *dst, va_list param)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = va_arg(param, char *);
	while (str)
	{
		j = 0;
		while (str[j])
		{
			dst[i + j] = str[j];
			j++;
		}
		i += j;
		j = 0;
		str = va_arg(param, char *);
	}
	return (dst);
}

char	*ft_strjoin_va(char *str, ...)
{
	va_list	param;
	va_list	p_cpy;
	char	*dst;
	size_t	total_len;

	if (str)
	{
		va_start(param, str);
		va_copy(p_cpy, param);
		total_len = len_sum(p_cpy);
		va_end(p_cpy);
		dst = ft_calloc(total_len + 1, sizeof(char));
		if (dst)
			dst = ft_strcat_va(dst, param);		
	}
	va_end(param);
	return (dst);
}
