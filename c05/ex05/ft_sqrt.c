/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:17:56 by somartin          #+#    #+#             */
/*   Updated: 2022/09/24 16:57:48 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	num;

	num = 1;
	if (nb == 0)
		return (0);
	while (nb > num * num)
		num++;
	if (nb == num * num)
		return (num);
	else
		return (0);
}
/*
#include <stdio.h>
int main (void)
{
	printf("%d\n",ft_sqrt(16));
}*/
/* Number X whose square (the result of X*X) is Y. 
 4 and −4 are square roots of 16, because 4^2 = (−4)^2 = 4*4 = 16. */
