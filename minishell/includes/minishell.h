/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:04:44 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 17:51:00 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>

# define MISH "mish$ "
# define PWD_SIZE 1024

typedef struct s_count{
	int		i;
	int		j;
	char	**env;
}	t_count;

typedef struct s_list
{
	char			**cmdflag;
	void			*content;
	char			*path;
	int				fd_out;
	int				fd_in;
	int				flag_redir;
	char			redir;
	struct s_list	*next;
}	t_list;

typedef struct s_opt
{
	t_list			**cmd;
	char			**allpip;
	char			**cmd_flags;
	unsigned char	last_pid;
	char			buf;
	char			*format;
	int				flag_pipe;
	int				count_pipes;
	int				fd_count;
	int				io[2];
	int				**fd;
	int				flag_first_pipe;
	int				fd_out;
	int				fd_in;
	int				flag_redir;
	char			*path;
}	t_opt;

typedef struct s_commands{
	char	*command;
	char	*string;
	int		fd_in;
	int		fd_out;
	char	*filename_in;
	char	*filename_out;
	char	*flygegeheim;
	int		str;
	int		i_exist;
}	t_commands;

int			ft_strlen(char *str);
void		echo(char *str, int i, char first);
int			ft_isalnum(int c);
char		*trimming(char *str);
char		*space_delete(char *str);
char		*transformation(char *str, int ret, char **true_env);
int			skip(char *str, int i);
char		*finalstr(char *str, int dl, char *tenv);
int			symbols(char c);
char		*ft_itoa(int n);
int			ft_isalpha(int c);
int			comamount(char *str);
int			ft_isascii(int c);
int			ministrlen(char *str, int i);
t_commands	*cut(char *str, t_commands	*parse);
char		*quotes_trim(char *str);
void		ft_echo(char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_strnstr(char *big, char *little);
void		minus(char ***env);
void		root(char ***env);
void		down(char ***env);
void		path(char ***env, char *newpwd);
char		*ft_strjoin(char *s1, char *s2);
void		cd(char *str, char ***env);
void		pwd(void);
void		do_env(char **env);
char		**ft_export(char *str, char **env);
int			envlen(char **env);
char		*strcopy(char *str);
char		**unset(char **env, char *str);
void		signal_cmd(void);
void		signals(void);
int			redirect(char *line);
int			double_redirect(char *line);
int			double_rev_redirect(char *stop_str);
int			rev_redirect(char *line);
void		command_do(t_opt *opt, char **env);
void		close_after_cmd(t_commands *cmd, int i);
void		dopipes(int i, t_opt *opt, t_commands *cmd);
void		last_pipe(int i, t_opt *opt, t_commands *cmd);
void		redirnpipe(t_commands *cmd, t_opt *opt, int flag, int i);
void		allcloser(t_commands *cmd, t_opt *opt);
void		allclose(t_opt *opt, int fd_in, int fd_out);
void		initpipes(t_opt *opt);
void		freeder(char **lines);
void		stdout_dup(t_commands *cmd, int fd_out, t_opt *opt, int i);
void		stdin_dup(t_commands *cmd, t_opt *opt, int flag, int i);
t_list		*ft_lstnew(char *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			numstr(char *s, char c);
void		ft_putendl_fd(char *s, int fd);
char		*ft_substr(char *s, int start, int len);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
char		*ft_strdup(char *s1);
char		**ft_split(char *s, char c);
char		**invalid_export(char *str, char **env);
int			lencmd(t_commands *parse);
char		*getpath(char *cmd, char **env);
void		signal_quit(int sig);
int			ft_strlen2(char *str, int i);
t_count		quotes_copy_inc(char *str, char **newstr, t_count counts);
t_count		quotes_and_apos_copy_inc(char *str, char **newstr, t_count counts);
t_count		quotes_and_apos_copy(char *str, char **newstr, t_count counts);
int			quotes_skip(char *str, int i);
char		*parse_redirects(char *str, t_commands	**parse, int i);
int			redirect_check(char c);
int			redirect_presence(char *str);
int			dd_redirect(char *str, int i, int j, t_commands	**parse);
int			redirect_default(char *str, int i, int j, t_commands	**parse);
int			double_back(char *str, int i, int j, t_commands	**parse);
int			back_redirect(char *str, int i, int j, t_commands	**parse);
char		*redirect_copy(char *str);
int			redirectlen(char *str);
int			redirect_skip(char *str, int i);
char		*ft_itoa(int n);
char		*exceptions(char *str, int i, int ret);
void		commands(char ***env, int i, t_opt *opt, t_commands **parse);
void		repeat_commands(char ***env, int i, t_commands **parse);
char		*say_my_name(char *str);
int			my_access(char *path);
void		swapenv(char ***env, char *oldpwd, char *pwd);
int			swap_export(char *str, char ***env, int plus);
int			check_dublicates(char *str, char **env);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_exit(char *str);
void		dublicate_exit(char *str);
int			ministrlen_string(char *str, int i);
void		exit_clean(char *str, char *str2);
void		commands_clean(t_commands *parse);
t_commands	*save_str(t_commands *parse, int len);
int			ministrlen2(char *str, int i);
int			ministrlen_string2(char *str, int i);
int			ft_isspace(char c);
int			check_echo(char *str, int i);
void		dot(char ***env);
void		invalid_cd(char *str, char ***env);
char		*ft_getenv(char *str, char **env);
void		invalid_minus(char ***env);
void		invalid_dot(char ***env);
void		invalid_path(char ***env, char *newpwd);
t_commands	*parser(char **str, t_commands *parse, char *argv, t_count counts);
void		sortenv(char **env, int	amount);
int			compare(char **env, char *str, int def, int amount);
int			check_plus(char **str);
void		concatenation_dublicate(char *str, char ***env, int	swap);
#endif
