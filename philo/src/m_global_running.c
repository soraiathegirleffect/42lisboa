/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_global_running.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:01:44 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:04:03 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_running(t_data *data, int value)
{
	pthread_mutex_lock(&data->m_running);
	data->running = value;
	pthread_mutex_unlock(&data->m_running);
}

int	is_running(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->m_running);
	value = data->running;
	pthread_mutex_unlock(&data->m_running);
	return (value);
}
