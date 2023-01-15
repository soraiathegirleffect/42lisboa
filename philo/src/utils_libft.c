/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:18 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/13 19:33:53 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	string_is_int(char **str)
{
	int	i;
	int	x;

	x = 1;
	while (str[x])
	{
		i = 0;
		while (str[x][i])
		{
			if (str[x][i] < '0' || str[x][i] > '9')
				return (1);
			i++;
		}
		x++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

long	ft_atoi(const char *str)
{
	long	rest;
	int		i;
	int		neg;

	neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	rest = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rest = (rest * 10);
		rest = rest + (str[i] - 48);
		i++;
	}
	return (rest * neg);
}
