#include "ft_printf.h"

static t_flags	distributor(t_flags f, int plen, int slen)
{
	if (!f.minus)
	{
		if (f.zero == ' ')
			f = printzero(f.width - plen - 2, f.zero, f);
		else
		{
			write(1, "0x", 2);
			f.print = f.print + 2;
			f = printzero(f.width - slen - 2, f.zero, f);
		}
	}
	if (f.accuracy > slen)
	{
		write(1, "0x", 2);
		f.print = f.print + 2;
		f = printzero(f.accuracy - slen, '0', f);
	}
	else if (f.zero == ' ')
	{
		write(1, "0x", 2);
		f.print = f.print + 2;
	}
	return (f);
}

t_flags	print_pointer(t_flags f, va_list ua)
{
	char	*s;
	int		slen;
	int		plen;

	s = ft_itoabase(va_arg(ua, unsigned long long), 16, 87);
	f = cleaner(f, s, s, 1);
	if (f.print == -1)
		return (f);
	f = check_flags(f, s, 'p');
	slen = ft_strlen(s);
	plen = slen;
	if (f.accuracy > plen)
		plen = f.accuracy;
	f = distributor(f, plen, slen);
	f = ft_putstr(s, f);
	if (f.minus)
		f = printzero(f.width - plen - 2, f.zero, f);
	free(s);
	return (f);
}
