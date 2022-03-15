#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr (const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dst, const char *src);
#endif