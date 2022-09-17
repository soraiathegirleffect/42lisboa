/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:12:12 by somartin          #+#    #+#             */
/*   Updated: 2022/09/15 18:39:38 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	troca;

	i = 0;
	while ((i + 1) < size)
	{
		if (tab[i] > tab [i + 1])
		{
			troca = tab[i];
			tab[i] = tab[i + 1];
			tab [i + 1] = troca;
			i = 0;
		}
		else
			i++;
	}
}
