/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:12:22 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:33:43 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_data(t_data *data, char **argv)
{
	pthread_mutex_init(&data->m_timeval, NULL);
	pthread_mutex_init(&data->m_count_thread, NULL);
	pthread_mutex_init(&data->m_running, NULL);
	set_count_thread(data, 0);
	data->count = 0;
	data->n_philo = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	data->start_time_secs = 0;
	data->start_time_usec = 0;
	data->program_time = 0;
	set_running(data, 1);
	if (argv[5])
		data->times_eat = ft_atoi(argv[5]);
	else
		data->times_eat = INT_MAX;
	init_data_philos(data);
}

void	init_data_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (t_philo **)malloc(sizeof(t_philo *) * (data->n_philo));
	ft_init_time(data);
	while (i < data->n_philo)
	{
		data->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		data->philo[i]->data = data;
		data->philo[i]->id_philo = i + 1;
		data->philo[i]->times_eat = 0;
		data->philo[i]->lastest_eat = ft_get_time(data);
		i++;
	}
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->philo[i]->lock, NULL) != 0)
		{
			print_errors(5);
			return (1);
		}
		i++;
	}
	return (0);
}
