/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:06 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:02:50 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	t_data			*data;
	pthread_mutex_t	lock;
	pthread_t		thread;
	int				id_philo;
	int				times_eat;
	long int		lastest_eat;
}		t_philo;

typedef struct s_data
{
	int				count_thread;
	int				count;
	int				n_philo;
	int				die;
	int				eat;
	int				sleep;
	int				times_eat;
	int				running;
	long int		start_time_secs;
	long int		start_time_usec;
	long int		program_time;
	t_philo			**philo;
	pthread_mutex_t	m_count_thread;
	pthread_mutex_t	m_running;
	pthread_mutex_t	m_timeval;
}		t_data;

int		string_is_int(char **str);
int		if_zero_negative(char **str);
int		if_max_int(char **str);
int		create_threads(t_data *data);
int		main(int argc, char **argv);
int		free_pthread(t_data *data);
int		parsing(int argc, char **argv);
int		count_eat(t_data *data, int i);
int		parse_errors(int argc, char **argv);
int		init_mutex(t_data *data);
void	lock_eat(t_data *data, int i);
void	lock_fork(t_data *data, int i);
void	init_data_philos(t_data *data);
void	print_time(t_data *data, int index, char *s);
void	ft_init_time(t_data *data);
void	*trythis(void *p);
void	check_if_dead(t_data *data);
void	free_mutex(t_data *data);
void	free_data(t_data *data);
void	print_data(t_data *data);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
long	ft_atoi(const char *str);
void	print_errors(int error);
void	init_data(t_data *data, char **argv);
long	ft_get_time(t_data *data);
void	ft_sleep(int num);
void	set_running(t_data *data, int value);
int		is_running(t_data *data);
void	set_count_thread(t_data *data, int value);
int		get_count_thread(t_data *data);
void	increment_count_thread(t_data *data);
void	decrement_count_thread(t_data *data);

#endif
