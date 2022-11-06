/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:58:45 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/28 14:40:24 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = -1;
	if (n == 0 || (!s1 && !s2) || !n)
		return (0);
	while (++i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
/*
int	main()
{
	char str1[] = "Abcdef";
	char str2[] = "aqCDEF";
	printf("minha funcao = %d\n", ft_memcmp(str2, str1, 3));
	printf("funcao = %d\n", memcmp(str2, str1, 3));
}*/
