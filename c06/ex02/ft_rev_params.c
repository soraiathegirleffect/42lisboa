/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:46:31 by somartin          #+#    #+#             */
/*   Updated: 2022/09/22 19:32:28 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	ac;

	ac = argc - 1;
	while (ac > 0)
	{
		i = 0;
		while (argv[ac][i] != '\0')
		{
			write (1, &argv[ac][i], 1);
			i++;
		}
		write (1, "\n", 1);
		ac--;
	}
	return (0);
}
