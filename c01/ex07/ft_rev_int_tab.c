/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:40:37 by somartin          #+#    #+#             */
/*   Updated: 2022/09/15 14:52:35 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	troca;

	a = 0;
	while (a < size / 2)
	{
		troca = tab[a];
		tab[a] = tab[size - a - 1];
		tab[size - a - 1] = troca;
		a++;
	}
}
