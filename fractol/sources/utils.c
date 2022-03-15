#include "fractol.h"

void	ft_bzero(void *s, int n)
{
	char	*c;
	int		x;

	x = 0;
	c = (char *)s;
	while (x < n)
	{
		c[x] = 0;
		x++;
	}
}

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		if (((unsigned char *)str1)[i] == '\0')
			return (0);
		i++;
	}
	return (0);
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

int	close(void)
{
	exit(0);
}
