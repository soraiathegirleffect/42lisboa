/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_global_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:02:09 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:04:15 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_count_thread(t_data *data, int value)
{
	pthread_mutex_lock(&data->m_count_thread);
	data->count_thread = value;
	pthread_mutex_unlock(&data->m_count_thread);
}

void	increment_count_thread(t_data *data)
{
	pthread_mutex_lock(&data->m_count_thread);
	data->count_thread++;
	pthread_mutex_unlock(&data->m_count_thread);
}

void	decrement_count_thread(t_data *data)
{
	pthread_mutex_lock(&data->m_count_thread);
	data->count_thread--;
	pthread_mutex_unlock(&data->m_count_thread);
}

int	get_count_thread(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->m_count_thread);
	value = data->count_thread;
	pthread_mutex_unlock(&data->m_count_thread);
	return (value);
}
