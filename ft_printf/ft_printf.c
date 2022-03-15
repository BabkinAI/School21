#include "ft_printf.h"

t_flags	check_flags(t_flags f, char *s, char type)
{
	if ((type == 'i') || (type == 'x'))
	{
		if ((f.faccuracy) && (*s == '0') && (f.accuracy == 0))
			*s = ' ';
		if (f.accuracy < 0)
			f.faccuracy = 0;
		if ((f.faccuracy) || (f.minus))
			f.zero = ' ';
		if ((f.faccuracy) && (*s == '-'))
			f.accuracy++;
	}
	if (type == 'p')
	{
		if ((f.faccuracy) && (*s == '0') && (f.accuracy == 0))
			*s = 0;
		if (f.faccuracy)
			f.zero = ' ';
	}
	return (f);
}

t_flags	printzero(int x, char c, t_flags f)
{
	while (x > 0)
	{
		write(1, &c, 1);
		x--;
		f.print ++;
	}
	return (f);
}

static t_flags	zeroflags(const char *str, int p)
{
	t_flags	t;

	t.minus = 0;
	t.zero = ' ';
	t.width = 0;
	t.accuracy = 0;
	t.faccuracy = 0;
	t.str = str;
	t.print = p;
	t.space = 0;
	t.plus = 0;
	t.octotorp = 0;
	return (t);
}

static t_flags	distributor(t_flags f, va_list ua)
{
	f = zeroflags(f.str, f.print);
	f.str++;
	f = specifier(f, ua);
	if (f.print == -1)
		return (f);
	if (*f.str == 'c')
		f = print_char(f, ua);
	else if (*f.str == 's')
		f = print_str(f, ua);
	else if (*f.str == 'p')
		f = print_pointer(f, ua);
	else if ((*f.str == 'd') || (*f.str == 'i'))
		f = print_int(f, ua, 1);
	else if (*f.str == 'u')
		f = print_int(f, ua, 0);
	else if (*f.str == 'x')
		f = print_sixteen(f, ua, 87, 16);
	else if (*f.str == 'X')
		f = print_sixteen(f, ua, 55, 16);
	else if (*f.str == 'o')
		f = print_sixteen(f, ua, 0, 8);
	else if (*f.str == '%')
		f = print_per_centum(f);
	return (f);
}

int	ft_printf(const char *str, ...)
{
	va_list	ua;
	t_flags	f;

	va_start (ua, str);
	f = zeroflags(str, 0);
	while (*f.str)
	{
		if (*f.str == '%')
		{
			f = distributor(f, ua);
			if (f.print == -1)
				return (-1);
		}
		else
		{
			write (1, &(*f.str), 1);
			f.print++;
		}
		f.str++;
	}
	return (f.print);
}
