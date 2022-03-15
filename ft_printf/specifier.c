#include "ft_printf.h"

static t_flags	minus_zero(t_flags f)
{
	while ((*f.str == '0') || (*f.str == '-') || (*f.str == ' ')
		|| (*f.str == '+') || (*f.str == '#'))
	{
		if (*f.str == '0')
			f.zero = '0';
		else if (*f.str == '-')
			f.minus = 1;
		else if (*f.str == ' ')
			f.space = 1;
		else if (*f.str == '+')
			f.plus = 1;
		else if (*f.str == '#')
			f.octotorp = 1;
		f.str++;
	}
	return (f);
}

static t_flags	accuracy(va_list ua, t_flags f)
{
	f.faccuracy = 1;
	f.accuracy = 0;
	f.str++;
	if (*f.str == '*')
	{
		f.accuracy = va_arg(ua, int);
		f.str++;
	}
	else if (ft_isdigit((int)*f.str))
	{	
		while (ft_isdigit((int)*f.str))
		{
			f.accuracy = ((*f.str - 48) + (f.accuracy * 10));
			f.str++;
		}
	}
	return (f);
}

static t_flags	width(va_list ua, t_flags f)
{
	if (*f.str == '*')
	{
		f.width = va_arg(ua, int);
		f.str++;
	}
	else if (ft_isdigit((int)*f.str))
	{
		f.width = 0;
		while (ft_isdigit((int)*f.str))
		{
			f.width = ((*f.str - 48) + (f.width * 10));
			f.str++;
		}
	}
	if (f.width < 0)
	{
		f.width = f.width * -1;
		f.minus = 1;
	}
	return (f);
}

t_flags	specifier(t_flags f, va_list ua)
{
	f = minus_zero (f);
	if ((*f.str != '0')
		&& ((*f.str == '*') || (ft_isdigit((int)*f.str))))
	{
		f = width(ua, f);
		if (f.width < 0)
			f.minus = 1;
	}
	while ((*f.str == ' ') || (*f.str == '+') || (*f.str == '#'))
	{
		if (*f.str == ' ')
			f.space = 1;
		else if (*f.str == '+')
			f.plus = 1;
		else if (*f.str == '#')
			f.octotorp = 1;
		f.str++;
	}
	if (*f.str == '.')
		f = accuracy(ua, f);
	if ((!ft_isalpha((int)*f.str)) && (*f.str != '%'))
		f.print = -1;
	return (f);
}
