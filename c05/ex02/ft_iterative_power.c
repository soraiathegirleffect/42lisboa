/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:39:03 by somartin          #+#    #+#             */
/*   Updated: 2022/09/24 17:06:59 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	while (power > 1)
	{
		result = result * nb;
		power--;
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (result);
}
/*
#include <stdio.h>
int main()
{
	int i;
	i = ft_iterative_power(5, 7);
	printf("%d", i);
	return 0;
}*/
/* 3 power 3 = 3*3*3 por ex 3>1 sim logo 3*3, 3-1=2, 2>1 sim logo 6*3 */
