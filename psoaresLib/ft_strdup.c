/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:38:56 by psoares-          #+#    #+#             */
/*   Updated: 2022/10/28 16:02:26 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dst;

	i = ft_strlen(s) + 1;
	dst = malloc(sizeof(char) * i);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s, i);
	return (dst);
}
