/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:43:14 by somartin          #+#    #+#             */
/*   Updated: 2022/09/25 20:10:56 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	tot;

	if (min >= max)
		return (0);
	tot = max - min;
	*range = malloc(sizeof(int) * tot);
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < tot)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (tot);
}
/*#include <stdio.h>
int main()
{
    int *p;
    int i;
    i = ft_ultimate_range(&p, 0, 20);
    printf("%d\n", i);
    while (i > 0)
    {
        printf("%d ", *p);
        p++;
        i--;
    }   
    free(p);
}*/
