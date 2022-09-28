/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:44:20 by somartin          #+#    #+#             */
/*   Updated: 2022/09/27 17:13:44 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0')
	{
		dest[x] = src[y];
		y++;
		x++;
	}
	dest[x] = '\0';
		return (dest);
}

int	ft_final_len(char **strs, int size, char *sep)
{
	int	i;
	int	fl;

	i = 0;
	fl = 0;
	while (i < size)
	{
		fl = fl + ft_strlen(strs[i]);
		i++;
	}
	fl = fl + (size - 1) * ft_strlen(sep) + 1;
	return (fl);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	i = 0;
	if (size == 0)
		return (malloc(1));
	str = malloc(sizeof(char) * ft_final_len(strs, size, sep));
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char *strs[4];

	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "rock";
	strs[3] = "lisboa42!";

	printf("%s\n", ft_strjoin(4, strs, " " ));
}*/
