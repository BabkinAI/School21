#include "ft_printf.h"

t_flags	print_str(t_flags f, va_list ua)
{
	int		x;
	char	*s;

	s = va_arg(ua, char *);
	if (s == NULL)
		s = "(null)";
	if ((f.faccuracy) && (f.accuracy < (int)ft_strlen(s)) && f.accuracy >= 0)
		x = f.width - f.accuracy;
	else
		x = f.width - (int)ft_strlen(s);
	if (!f.minus)
		f = printzero(x, f.zero, f);
	if ((f.faccuracy) && (f.accuracy < (int)ft_strlen(s)) && f.accuracy >= 0)
		f = ft_putstrn(s, f.accuracy, f);
	else
		f = ft_putstr(s, f);
	if (f.minus)
	{
		f.zero = ' ';
		f = printzero(x, f.zero, f);
	}
	return (f);
}

t_flags	print_char(t_flags f, va_list ua)
{
	char	c;
	int		x;

	c = va_arg(ua, int);
	x = f.width - 1;
	if (f.minus)
	{
		f.zero = ' ';
		write(1, &c, 1);
		f.print ++;
	}
	f = printzero(x, f.zero, f);
	if (!f.minus)
	{
		write(1, &c, 1);
		f.print ++;
	}
	return (f);
}

t_flags	print_sixteen(t_flags f, va_list ua, char c, int scale)
{
	char	*s;
	int		plen;

	s = ft_itoabase(va_arg(ua, unsigned int), scale, c);
	f = cleaner(f, s, s, 1);
	if (f.print == -1)
		return (f);
	f = check_flags(f, s, 'x');
	if ((f.faccuracy) && (*s == '0') && (f.accuracy == 0))
		*s = ' ';
	plen = ft_strlen(s);
	if (f.accuracy > plen)
		plen = f.accuracy;
	if (f.faccuracy)
		f.zero = ' ';
	if (!f.minus)
		f = printzero(f.width - plen, f.zero, f);
	if (f.accuracy > (int)ft_strlen(s))
		f = printzero(f.accuracy - ft_strlen(s), '0', f);
	f = ft_putstr(s, f);
	if (f.minus)
		f = printzero(f.width - plen, f.zero, f);
	free(s);
	return (f);
}

t_flags	print_per_centum (t_flags f)
{
	int		x;

	x = f.width - 1;
	if (f.minus)
	{
		f.zero = ' ';
		write(1, "%", 1);
		f.print ++;
	}
	f = printzero(x, f.zero, f);
	if (!f.minus)
	{
		write(1, "%", 1);
		f.print ++;
	}
	return (f);
}
