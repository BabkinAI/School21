#include "minitalk.h"

static void	save_symbol(char buff)
{
	static char		string_buff[1152];
	static size_t	string_count = 0;

	string_buff[string_count] = buff;
	if (buff == 0)
	{
		write(1, &string_buff, string_count);
		write(1, "\n", 1);
		string_count = 0;
	}
	else
		string_count++;
	if (string_count == 1151)
	{
		write(1, &string_buff, string_count);
		string_count = 0;
	}
}

static void	handler(int i)
{
	static char		buff = 0;
	static size_t	count = 0;

	if (i == SIGUSR1)
	{
		count++;
		buff = (buff << 1) + 1;
	}
	else
	{
		count++;
		buff = (buff << 1);
	}
	if (count == 8)
	{
		count = 0;
		save_symbol(buff);
		buff = 0;
	}
}

int	main(void)
{
	int	pid;

	ft_putnbr_fd(pid = getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
	}
}
