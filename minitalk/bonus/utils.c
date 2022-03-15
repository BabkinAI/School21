#include <unistd.h>

static int	digits (int n)
{
	int	x;

	x = 1;
	while (n > 9)
	{
		n = n / 10;
		x = x * 10;
	}
	return (x);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	x;
	size_t	m;

	i = 0;
	x = 0;
	m = 1;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m = m * -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		x = ((str[i] - 48) + (x * 10));
		i++;
	}
	return (x * m);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		x;
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		x = digits(n);
		while (x)
		{
			c = ((n / x) + 48);
			write(fd, &c, 1);
			n = n % x;
			x = x / 10;
		}
	}
}
