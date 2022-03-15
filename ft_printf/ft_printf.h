#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	char		minus;
	char		zero;
	char		space;
	char		plus;
	char		octotorp;
	int			width;
	int			accuracy;
	char		faccuracy;
	const char	*str;
	int			print;
}	t_flags;

t_flags	ft_putstrn (char *str, size_t n, t_flags f);
t_flags	ft_putstr (char *str, t_flags f);
int		ft_printf(const char *str, ...);
char	*ft_itoabase(unsigned long long n, int f, int g);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
size_t	ft_strlen (const char *str);
void	*ft_memset(void *src, int c, size_t x);
char	*ft_strncpy(char *dest, char *src, int i);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
t_flags	printzero(int x, char c, t_flags f);
t_flags	specifier(t_flags f, va_list ua);
t_flags	print_str(t_flags f, va_list ua);
t_flags	print_char(t_flags f, va_list ua);
t_flags	print_pointer(t_flags f, va_list ua);
t_flags	print_int(t_flags f, va_list ua, char swtch);
t_flags	print_sixteen(t_flags f, va_list ua, char c, int scale);
t_flags	print_per_centum (t_flags f);
t_flags	check_flags(t_flags f, char *s, char type);
t_flags	cleaner(t_flags	f, char	*s,	char *str, char swtch);
#endif