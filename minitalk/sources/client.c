#include "minitalk.h"

static void	sent(char ch, int pid)
{
	int	c;

	c = 128;
	while (c)
	{
		if (ch & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(25);
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		sent(*argv[2], pid);
		argv[2]++;
	}
	sent(0, pid);
}
