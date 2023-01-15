/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:29 by ifreire-          #+#    #+#             */
/*   Updated: 2023/01/11 13:35:57 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	if_zero_negative(char **str)
{
	int	x;

	x = 1;
	while (str[x])
	{
		if (ft_atoi(str[x]) <= 0)
			return (1);
		x++;
	}
	return (0);
}

int	if_max_int(char **str)
{
	int	x;

	x = 1;
	while (str[x])
	{
		if (ft_atoi(str[x]) > INT_MAX)
			return (1);
		x++;
	}
	return (0);
}

void	print_errors(int error)
{
	if (error == 1)
		ft_putstr_fd("Error, the numbers of arguments needs to be 5 or 6", 2);
	else if (error == 2)
		ft_putstr_fd("Error, the arguments needs to be type integer", 2);
	else if (error == 3)
		ft_putstr_fd("Error, the arguments can't be negative or zero", 2);
	else if (error == 4)
		ft_putstr_fd("Error, the arguments can't be higher than MAX_INT", 2);
	else if (error == 5)
		ft_putstr_fd("Error, while initing mutexs\n", 2);
	else if (error == 6)
		ft_putstr_fd("Error, while creating pthreads\n", 2);
}

int	parsing(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (string_is_int(argv) == 1)
		return (2);
	if (if_zero_negative(argv) == 1)
		return (3);
	if (if_max_int(argv) == 1)
		return (4);
	return (0);
}

int	parse_errors(int argc, char **argv)
{
	int	error;

	error = 0;
	error = parsing(argc, argv);
	if (error != 0)
	{
		print_errors(error);
		return (1);
	}
	return (0);
}
