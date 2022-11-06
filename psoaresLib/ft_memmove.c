/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:41:37 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/28 14:29:07 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = dest;
	if (a < b)
	{
		while (n--)
			b[n] = a[n];
	}
	else
		ft_memcpy(b, a, n);
	return (dest);
}

/*
int	main(void)
{
	char	str1;
	char	s2[] = "Mas nao sou";
	char	
	char	str2;


	//memmove(s1, s2, sizeof(s2));
	ft_memmove(s1, s2, sizeof(s2));

	printf("Teste: %s", s1);
}*/