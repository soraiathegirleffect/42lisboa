/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:37:25 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/26 15:31:33 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p = (unsigned char)c;
		p++;
	}
	return (s);
}

/*int	main(void)
{
	char s1[] = "Eu sou louco";
	char *str1;
	char s2[] = "Eu sou louco";
	char *str2;

	ft_memset(s1 + 3, 'L', 3);
	memset(s2 + 3, 'L', 3);
	str1 = s1;
	str2 = s2;

	printf("Meu:%s", s1);
	printf("Original:%s", s2);
}*/