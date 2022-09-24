/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:09:43 by somartin          #+#    #+#             */
/*   Updated: 2022/09/24 21:01:04 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
/*
#include <stdio.h>
int main()
{
	int i;
	i = ft_fibonacci(7);
	printf("%d", i);
}*/
/* 0, 1, 1, 2, 3, 5, 8, -13-, 21, 34, 55,
cada termo subsequente corresponde à soma dos dois anteriores.
fn = fn-1 + fn-2 */
