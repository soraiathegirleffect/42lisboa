/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 06:35:46 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:16:03 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	lock_fork2(t_data *data, int i)
{
	if (!is_running(data))
	{
		pthread_mutex_unlock(&data->philo[i]->lock);
		return ;
	}
	pthread_mutex_lock(&data->philo[i + 1]->lock);
	if (!is_running(data))
	{
		pthread_mutex_unlock(&data->philo[i + 1]->lock);
		pthread_mutex_unlock(&data->philo[i]->lock);
		return ;
	}
	print_time(data, data->philo[i]->id_philo, \
		"has taken a fork\n");
}

void	lock_fork1(t_data *data, int i)
{
	if (!is_running(data))
	{
		pthread_mutex_unlock(&data->philo[i]->lock);
		return ;
	}
	pthread_mutex_lock(&data->philo[0]->lock);
	if (!is_running(data))
	{
		pthread_mutex_unlock(&data->philo[0]->lock);
		pthread_mutex_unlock(&data->philo[i]->lock);
		return ;
	}
	print_time(data, data->philo[i]->id_philo, \
		"has taken a fork\n");
}

void	lock_fork(t_data *data, int i)
{
	if (!is_running(data))
		return ;
	pthread_mutex_lock(&data->philo[i]->lock);
	if (!is_running(data))
	{
		pthread_mutex_unlock(&data->philo[i]->lock);
		return ;
	}
	print_time(data, data->philo[i]->id_philo, "has taken a fork\n");
	if ((i + 1) == data->n_philo)
		lock_fork1(data, i);
	else
		lock_fork2(data, i);
}

void	*trythis(void *p)
{
	t_philo	*philo;
	t_data	*data;
	int		index;

	philo = (t_philo *)p;
	data = (t_data *)philo->data;
	index = (philo->id_philo - 1);
	increment_count_thread(data);
	if ((index % 2) != 0)
		ft_sleep(data->eat);
	while ((count_eat(data, index) == 0) && (is_running(data)))
	{
		lock_fork(data, index);
		lock_eat(data, index);
		count_eat(data, index);
		print_time(data, data->philo[index]->id_philo, "is sleeping\n");
		ft_sleep(data->sleep);
		print_time(data, data->philo[index]->id_philo, "is thinking\n");
		usleep(100);
	}
	decrement_count_thread(data);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (parse_errors(argc, argv) == 1)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	init_data(data, argv);
	if (init_mutex(data) != 0 || create_threads(data) != 0)
		return (1);
	if (data->n_philo == 1)
	{
		ft_sleep(data->die);
		print_time(data, 1, "has died\n");
		set_running(data, 0);
		set_count_thread(data, 0);
	}
	while (is_running(data))
		check_if_dead(data);
	free_data(data);
	return (0);
}
