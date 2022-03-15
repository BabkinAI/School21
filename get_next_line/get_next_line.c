#include "get_next_line.h"

static char	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	x;

	x = 0;
	p = malloc(size * count);
	if (p == NULL)
		return (p);
	*p = 0;
	return (p);
}

static char	*check_copy(char **copy, char **line)
{
	char	*linebrake;

	linebrake = NULL;
	if (*copy)
	{
		if (ft_strchr(*copy, '\n'))
		{
			linebrake = ft_strchr(*copy, '\n');
			*linebrake = '\0';
			*line = ft_strdup(*copy);
			linebrake++;
			ft_strcpy(*copy, linebrake);
		}
		else
		{
			*line = ft_strdup(*copy);
			free(*copy);
			*copy = NULL;
		}
		return (linebrake);
	}
	else
		*line = ft_calloc(1, 1);
	return (linebrake);
}

int	gnl_help(int fd, char **line, int buflen, char buf[BUFFER_SIZE + 1])
{
	char			*linebrake;
	static char		*copy;

	linebrake = check_copy(&copy, line);
	while (!linebrake)
	{
		buflen = read(fd, buf, BUFFER_SIZE);
		buf[buflen] = '\0';
		if (buflen == 0)
			return (0);
		if (ft_strchr(buf, '\n'))
		{
			linebrake = ft_strchr(buf, '\n');
			*linebrake = '\0';
			linebrake++;
			if (copy)
				free(copy);
			copy = ft_strdup(linebrake);
		}
		*line = ft_strjoin(*line, buf);
		if (!*line)
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				buflen;
	char			buf[BUFFER_SIZE + 1];

	buflen = 1;
	buf[buflen] = '\0';
	if ((fd < 0 ) || (!line) || (BUFFER_SIZE < 1) || (read(fd, 0, 0) < 0))
		return (-1);
	return (gnl_help(fd, line, buflen, buf));
}
