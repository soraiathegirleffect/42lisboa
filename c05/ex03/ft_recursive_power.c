/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:53:54 by somartin          #+#    #+#             */
/*   Updated: 2022/09/24 21:07:35 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power > 1)
	{
		result = result * ft_recursive_power(nb, (power - 1));
		return (result);
		nb--;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_recursive_power(5, 7));
}*/
