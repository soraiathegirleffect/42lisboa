/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-assu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:17 by fde-assu          #+#    #+#             */
/*   Updated: 2022/11/17 12:49:20 by fde-assu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	getlen(int pid)
{
	int	ret;

	ret = 0;
	while (pid > 0)
	{
		pid = pid / 10;
		ret++;
	}
	return (ret);
}

char	*print_pid(int pid, int pid_len)
{
	char	ret[30];
	char	*retu;

	if (pid <= 0)
	{
		write(1, "Something is not right", 22);
		return (NULL);
	}
	else
	{
		while (pid_len)
		{
			ret[pid_len - 1] = (pid % 10) + '0';
			pid = pid / 10;
			pid_len--;
		}
		retu = &ret[0];
		return (retu);
	}
}

void	server(int signal)
{
	static int	i;
	static int	wrt;
	int			pwrvl[8];
	int			j;

	j = 0;
	pwrvl[j] = 128;
	while (j++ <= 8)
		pwrvl[j] = pwrvl[j - 1] / 2;
	if (signal == SIGUSR2)
		wrt += pwrvl[i];
	i++;
	if (i == 8)
	{
		write(1, &wrt, 1);
		i = 0;
		wrt = 0;
	}
}

int	main(void)
{
	int		pid;
	int		pid_len;
	char	*pid_char;

	pid = getpid();
	pid_len = getlen(pid);
	pid_char = print_pid(pid, pid_len);
	write(1, "PID:", 4);
	write(1, pid_char, pid_len);
	write(1, "\n", 1);
	signal(SIGUSR1, server);
	signal(SIGUSR2, server);
	while (1)
		pause();
}
