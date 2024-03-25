#include "lexer.h"

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