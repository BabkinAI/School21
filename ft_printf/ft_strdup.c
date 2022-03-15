#include "ft_printf.h"

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
