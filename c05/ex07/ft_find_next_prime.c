/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:56:24 by somartin          #+#    #+#             */
/*   Updated: 2022/09/24 21:08:37 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	p;

	p = 2;
	if (nb < 2)
		return (0);
	while (p <= nb / p)
	{
		if (nb % p == 0)
			return (0);
		p++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (nb >= 2)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	int i;
	i = ft_find_next_prime(4);
	printf("1: %d\n", i);
}*/
/* Númer primo é nr > 1 que possuem apenas 2 divisores
(por 1 e por eles proprios)
3/3 e /1 mas 3/2 N! ,, 4/4 4/1 mas 4/2 existe logo nao e primo
4%2 = 0 (resto) logo return 0. */
