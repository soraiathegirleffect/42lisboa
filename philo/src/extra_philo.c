/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:48:06 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:15:22 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->n_philo == 1)
	{
		print_time(data, 1, "has taken a fork\n");
		return (0);
	}
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i]->thread, \
			NULL, trythis, data->philo[i]) != 0)
		{
			print_errors(6);
			return (1);
		}
		usleep(1);
		i++;
	}
	return (0);
}

int	count_eat(t_data *data, int i)
{
	if (data->philo[i]->times_eat >= data->times_eat)
	{
		data->count++;
		if (data->count >= data->n_philo)
			set_running(data, 0);
	}
	return (0);
}

void	check_if_dead(t_data *data)
{
	int			i;
	long int	dif;

	i = 0;
	usleep(10);
	while (i < data->n_philo)
	{
		dif = ft_get_time(data) - data->philo[i]->lastest_eat;
		if ((data->die - dif) <= 0)
		{
			print_time(data, data->philo[i]->id_philo, "died\n");
			set_running(data, 0);
			break ;
		}
		i++;
	}
}

void	lock_eat(t_data *data, int i)
{
	print_time(data, data->philo[i]->id_philo, "is eating\n");
	data->philo[i]->times_eat += 1;
	data->philo[i]->lastest_eat = ft_get_time(data);
	ft_sleep(data->eat);
	pthread_mutex_unlock(&data->philo[i]->lock);
	if ((i + 1) == data->n_philo)
		pthread_mutex_unlock(&data->philo[0]->lock);
	else
		pthread_mutex_unlock(&data->philo[i + 1]->lock);
}
