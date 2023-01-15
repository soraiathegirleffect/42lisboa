/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:10:57 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:52:48 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	free_pthread(t_data *data)
{
	int	i;

	while (get_count_thread(data) > 0)
	{
		usleep(10);
	}
	i = 0;
	if (data->n_philo > 1)
	{
		while (i < data->n_philo)
		{
			pthread_detach(data->philo[i]->thread);
			i++;
		}
	}
	return (0);
}

void	free_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philo[i]->lock);
		i++;
	}
	pthread_mutex_destroy(&data->m_timeval);
	pthread_mutex_destroy(&data->m_count_thread);
	pthread_mutex_destroy(&data->m_running);
}

void	free_data(t_data *data)
{
	int	i;

	free_pthread(data);
	free_mutex(data);
	i = 0;
	while (i < data->n_philo)
		free(data->philo[i++]);
	if (data->philo)
		free(data->philo);
	if (data)
		free(data);
}

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->philo[i])
	{
		printf("ID_Philo:%d\n", data->philo[i]->id_philo);
		printf("MAX_EAT:%d\n", data->philo[i]->times_eat);
		printf("\n---\n");
		i++;
	}
}
