/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:54:22 by psoares-          #+#    #+#             */
/*   Updated: 2022/11/02 13:48:02 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
	{
		return (len);
	}
	if (size > 0)
	{
		while ((i < (size - 1)) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (len);
}

/*
#include <string.h>

int	main(void)
{
	char	str1[] = "Louco na C";
	char	str2[] = "Louco no teu rabo";

	printf("%s %ld\n", str1, ft_strlcpy(str1, str2, 8));
	printf("%s %d\n", str1, strlcpy(str1, str2, 8));
}*/