/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:27:45 by somartin          #+#    #+#             */
/*   Updated: 2022/09/24 20:57:01 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 2))
	{
		if ((nb % i) == 0)
			return (0);
		else
			i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	int i;
	i = ft_is_prime(997);
	printf("I: %d\n", i);
}
*/
/* Número primo é nr > 1 que possuem apenas 2divisores
(por 1 e por eles proprios)
3/3 e /1 mas 3/2 N! ,, 4/4 4/1 mas 4/2 existe logo nao e primo 
4%2 = 0 (resto) logo return 0. */
