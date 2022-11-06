/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:35 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/28 15:00:15 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[j] && (j < (size - dlen - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size <= dlen)
		dlen = size;
	return (dlen + slen);
}
