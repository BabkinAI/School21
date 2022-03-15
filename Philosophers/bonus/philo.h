/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:28:45 by kmars             #+#    #+#             */
/*   Updated: 2021/08/17 15:18:21 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

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
	t_time			dead_incoming;
	int				meals_amount;
	int				amount_meals;
	sem_t			*sem;
	sem_t			*etiquette;
	sem_t			*meals;
	sem_t			*talk;
	int				pid;
	t_time			start;
	int				amount;	
}	t_philo;

typedef struct s_imaphores
{
	sem_t	*sem;
	sem_t	*etiquette;
	sem_t	*talk;
}	t_imaphores;

void	chek_input(int argc, char **argv);
int		ft_atoi(const char *str);
t_philo	*philo_init(char **argv, t_imaphores simaphores, int argc);
t_time	time_start(void);
long	time_stop(t_time time);
void	philo(t_philo	*philosopher, int argc);
void	unlink_philo(void);
void	*philo_check_1(void *buf);
void	*philo_check_2(void *buf);
void	dead(t_philo	*philosophers, int philo_amount);
sem_t	*meals_init(int i);
void	*all_full(void *buf);
char	*ft_strjoin(char *s1, char *s2, char swtch);
char	*ft_itoa(int n);
void	waiter_join(pthread_t waiter, t_philo *philosophers, int argc);

#endif