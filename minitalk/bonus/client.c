#include "minitalk.h"
#include <stdio.h>

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

static void	minitalk_itoa(int client_pid, int pid)
{
	char	digit;
	size_t	rank;
	int		pid_copy;

	pid_copy = client_pid;
	rank = 1;
	while (pid_copy)
	{
		pid_copy = pid_copy / 10;
		rank = rank * 10;
	}
	while (client_pid)
	{
		digit = (client_pid / rank) + 48;
		client_pid = client_pid % rank;
		rank = rank / 10;
		sent(digit, pid);
	}
	sent(0, pid);
}

static void	ok(int i)
{
	static char	swtch = 1;

	if (i == SIGUSR1)
	{
		write(1, "Message is received\n", 20);
		swtch = 0;
	}
	else if (swtch)
	{
		write(1, "Message is not received\n", 24);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		client_pid;

	signal(SIGUSR1, ok);
	signal(SIGUSR2, ok);
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	minitalk_itoa(client_pid = getpid(), pid);
	while (*argv[2])
	{
		sent(*argv[2], pid);
		argv[2]++;
	}
	sent(0, pid);
	usleep(10000);
	kill(client_pid, SIGUSR2);
}
