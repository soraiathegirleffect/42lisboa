/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:38:57 by psoares-          #+#    #+#             */
/*   Updated: 2022/11/04 14:55:00 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*ptr;

	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ptr = (char *)malloc(sizeof(char));
		*ptr = 0;
		return (ptr);
	}
	if (len >= ft_strlen(s))
		len = (ft_strlen(s) - start);
	ptr = (char *)malloc(1 + len);
	if (!ptr)
		return (NULL);
	while (start < ft_strlen(s) && j < len)
	{
		ptr[j] = s[start];
		j++;
		start++;
	}
	ptr[j] = 0;
	return (ptr);
}
