/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:50 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/28 14:39:38 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	if (c == 0)
		return (s1 + ft_strlen((char const *)s1));
	while (n-- > 0)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		s1++;
	}
	return (NULL);
}

/*
int main(void)
{
	char s1[] = "Louco na C";

	printf("Antes  = %s \n", s1);
	ft_memchr(s1, 2, 0);
	printf("%p\n", ft_memchr(s1, 2, 0));
	printf("Depois = %s \n", s1);

	printf("======================================\n");

	printf("Antes  = %s \n", s1);
	memchr(s1, 2, 0);
	printf("%p\n", memchr(s1, 2, 0));
	printf("Depois = %s \n", s1);

}*/

/*
int	main(void)
{
	char	str[] = "banana";
	printf("char:%c |string:%p\n", 'c', memchr(str, 'n', 10));
	printf("char:%c |string:%p", 'c', ft_memchr(str, 'n', 10));

}*/