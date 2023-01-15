/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:23 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/14 20:01:05 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_init_time(t_data *data)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	data->start_time_secs = current_time.tv_sec;
	data->start_time_usec = current_time.tv_usec;
}

long	ft_get_time(t_data *data)
{
	struct timeval	current_time;
	long int		exe_time;

	gettimeofday(&current_time, NULL);
	exe_time = ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000) \
		- (data->start_time_secs * 1000 + data->start_time_usec / 1000));
	return (exe_time);
}

void	print_time(t_data *data, int index, char *s)
{
	if (!is_running(data))
		return ;
	pthread_mutex_lock(&data->m_timeval);
	if (!is_running(data))
	{
		pthread_mutex_unlock(&data->m_timeval);
		return ;
	}
	printf("%li - %d %s", ft_get_time(data), index, s);
	pthread_mutex_unlock(&data->m_timeval);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(int num)
{
	unsigned long	time_end;

	time_end = get_time() + num;
	while (get_time() < time_end)
		usleep(10);
}
