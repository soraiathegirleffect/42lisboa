/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:43:31 by psoares-          #+#    #+#             */
/*   Updated: 2022/11/04 17:42:16 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *s, char c)
{
	int	is_word;
	int	n_word;

	is_word = 0;
	n_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			n_word++;
		}
		else if (is_word == 1 && *s == c)
		{
			is_word = 0;
		}
		s++;
	}
	return (n_word);
}

static int	ft_len(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		word;

	if (!s)
		return (NULL);
	word = ft_word_count((char *)s, c);
	ptr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		ptr[i] = ft_substr((char *)s, 0, ft_len((char *)s, c));
		if (!ptr[i])
			return (NULL);
		s += ft_len((char *)s, c);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

/*
int main(void)
{
	char s1[] = "             n ";
	char **ret;
	int i;

	i = -1;
	ret = ft_split(s1, ' ');
	while (ret[++i])
		printf("%s\n", ret[i]);
}
*/