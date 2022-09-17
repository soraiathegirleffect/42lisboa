/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:19:32 by somartin          #+#    #+#             */
/*   Updated: 2022/09/11 18:21:52 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	nr;

	nr = '0';
	while (nr <= '9')
	{
		write (1, &nr, 1);
		nr++;
	}
}
/*
int main (void)
{ft_print_numbers();
}
*/
