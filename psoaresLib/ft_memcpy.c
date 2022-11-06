/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:53:26 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/28 14:27:11 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char	s1[] = "Quero ser lindo";
	char	str1;
	char	s2[] = "Mas nao sou";
	char	str2;

	str1 = s1;
	str2 = s2;

	memcpy(s1, s2, sizeof(s2));
	ft_memcpy(s1, s2, sizeof(s2));

	printf("Teste: %s", s2);
	
}*/