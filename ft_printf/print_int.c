#include "ft_printf.h"

static int	slen_strlen (t_flags f, char *s, char swtch)
{
	int	strlen;
	int	slen;

	slen = ft_strlen(s);
	if ((f.faccuracy) && (f.accuracy > slen))
		slen = f.accuracy;
	strlen = slen;
	if (f.width > strlen)
		strlen = f.width;
	if (swtch)
		return (slen);
	else
		return (strlen);
}

static char	*str_int3 (int strlen, int slen, char *str, char *s)
{
	int	i;

	i = strlen - slen;
	if (*s == '-')
	{
		*str = *s;
		s++;
		i++;
	}
	str = ft_strncpy(str, s, i);
	return (str);
}

static char	*str_int2 (int strlen, int accuracy, char *str, char *s)
{
	int		i;

	i = strlen - ft_strlen(s);
	if (accuracy >= (int)ft_strlen(s))
	{
		i = strlen - accuracy;
		accuracy = accuracy - ft_strlen(s);
		strlen = -1;
	}
	if (*s == '-')
	{
		str[i] = *s;
		i++;
		s++;
	}
	while ((accuracy > 0) && (strlen == -1))
	{
		str[i] = '0';
		i++;
		accuracy--;
	}
	str = ft_strncpy(str, s, i);
	return (str);
}

static char	*str_int(int accuracy, char *str, char *s)
{
	int		i;
	int		slen;

	slen = ft_strlen(s);
	if (accuracy >= slen)
	{
		accuracy = accuracy - slen;
		slen = -1;
	}
	i = 0;
	if (s[i] == '-')
	{
		str[i] = *s;
		i++;
		s++;
	}
	while ((accuracy > 0) && (slen == -1))
	{
		str[i] = '0';
		i++;
		accuracy--;
	}
	str = ft_strncpy(str, s, i);
	return (str);
}

t_flags	print_int(t_flags f, va_list ua, char swtch)
{
	char	*str;
	char	*s;

	if (swtch)
		s = ft_itoa(va_arg(ua, int));
	else
		s = ft_itoabase(va_arg(ua, unsigned int), 10, 0);
	f = cleaner(f, s, s, 1);
	if (f.print == -1)
		return (f);
	f = check_flags(f, s, 'i');
	str = ft_calloc(slen_strlen (f, s, 0) + 1, 1);
	f = cleaner(f, s, str, 2);
	if (f.print == -1)
		return (f);
	ft_memset(str, f.zero, slen_strlen (f, s, 0));
	if (f.zero == '0')
		str = str_int3(slen_strlen (f, s, 0), slen_strlen (f, s, 1), str, s);
	if (f.minus)
		str = str_int(f.accuracy, str, s);
	if ((!f.minus) && (f.zero == ' '))
		str = str_int2(slen_strlen (f, s, 0), f.accuracy, str, s);
	f = ft_putstr(str, f);
	f = cleaner(f, s, str, 3);
	return (f);
}
