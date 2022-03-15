#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*copy;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = 0;
	free(s1);
	return (copy);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*copystr;

	i = 0;
	while (str[i])
		i++;
	copystr = malloc(i + 1);
	if (!copystr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copystr[i] = str[i];
		i++;
	}
	copystr[i] = 0;
	return (copystr);
}

char	*ft_strchr (const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (((char *)str)[i])
	{
		if (((char *)str)[i] == ch)
			return (&((char *)str)[i]);
		i++;
	}
	if (((char *)str)[i] == ch)
		return (&((char *)str)[i]);
	return (NULL);
}
