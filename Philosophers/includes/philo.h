/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:28:45 by kmars             #+#    #+#             */
/*   Updated: 2021/08/16 16:59:40 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_time
{
	struct timeval	tv;
	struct timezone	tz;
}	t_time;

typedef struct s_philo
{
	int				number;
	pthread_t		thread;
	int				ttd;
	int				tte;
	int				tts;
	char			*talk_fork;
	int				fork_talk;
	char			*talk_eat;
	int				eat_talk;
	char			*talk_sleep;
	int				sleep_talk;
	char			*talk_think;
	int				think_talk;
	t_time			dead_incoming;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	*talk_mutex;
	int				meals_amount;
	t_time			start;
}	t_philo;

int				ft_atoi(const char *str);
size_t			chek_input(int argc, char **argv);
pthread_mutex_t	*mutex_init(int forks_amount);
t_philo			*philo_init(char **argv,
					pthread_mutex_t *mutex, pthread_mutex_t talk_mutex);
void			*philo(void *buf);
t_time			time_start(void);
long			time_stop(t_time time);
void			philo_join(int philo_amount, t_philo *philosophers);
void			philo_talk(t_time time, char *message, int i);
void			ft_putnbr(int n);
char			*ft_itoa(int n);
char			*ft_strjoin(char *s1, char *s2, char swtch);
size_t			ft_strlen(const char *str);
int				philo_check_1(t_philo	*philosophers, int philo_amount);
int				philo_check_2(t_philo	*philosophers,
					int philo_amount, int meals_amount);
void			all_free(pthread_mutex_t *mutex,
					t_philo *philosophers, int	philo_amount);
#endif