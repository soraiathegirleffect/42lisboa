/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:42:28 by somartin          #+#    #+#             */
/*   Updated: 2022/09/25 20:03:48 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;
	int	tot;

	if (min >= max)
		return (NULL);
	tot = max - min;
	dest = malloc(sizeof(int) * tot);
	if (dest == 0)
		return (NULL);
	i = 0;
	while (i < tot)
	{
		dest[i] = min + i;
		i ++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    int *p;
    int i;
	i = 0;
    p = ft_range(0, 20);
    while (i < 20)
    {
        printf("%d ", p[i]);
        i++;
    }   
    free(p);
}*/
