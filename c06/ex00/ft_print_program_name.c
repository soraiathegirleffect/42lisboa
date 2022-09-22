/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:05:09 by somartin          #+#    #+#             */
/*   Updated: 2022/09/22 19:28:18 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	while (*argv[0] && argc > 0)
	{
		write(1, &*argv[0], 1);
		argv[0]++;
	}
	write(1, "\n", 1);
	return (0);
}
