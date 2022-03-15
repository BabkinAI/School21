#include "ft_printf.h"

char	*ft_strncpy(char *dest, char *src, int i)
{
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	return (dest);
}
