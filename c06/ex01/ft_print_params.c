/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:29:51 by somartin          #+#    #+#             */
/*   Updated: 2022/09/22 19:31:30 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	ac;

	ac = 1;
	while (argc > ac)
	{
		i = 0;
		while (argv[ac][i] != '\0')
		{
			write (1, &argv[ac][i], 1);
			i++;
		}
		write (1, "\n", 1);
		ac++;
	}
	return (0);
}
