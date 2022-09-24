/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:22:34 by somartin          #+#    #+#             */
/*   Updated: 2022/09/11 18:26:28 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	negpos;

	if (n < 0)
	{
		negpos = 'N';
		write(1, &negpos, 1);
	}
	else
	{
		negpos = 'P';
		write(1, &negpos, 1);
	}
}
/*
int main (void)
{ ft_is_negative(-1);
}
*/
