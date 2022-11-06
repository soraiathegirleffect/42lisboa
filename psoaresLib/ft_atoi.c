/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:59:14 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/28 15:10:24 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				res;
	int				sinal;

	i = 0;
	res = 0;
	sinal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		res = (res * 10) + (str[i++] - '0');
	return (res * sinal);
}

/*
int main()
{
	char	*str;
	str = "  +764564566976777674677474";
	printf("minha funcao = %d\n", ft_atoi(str));
	printf("funcao normal = %d\n", atol(str));
}*/