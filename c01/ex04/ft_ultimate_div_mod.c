/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:53:38 by somartin          #+#    #+#             */
/*   Updated: 2022/09/14 20:34:23 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	fixa;
	int	fixb;

	fixa = *a;
	fixb = *b;
	*a = fixa / fixb;
	*b = fixa % fixb;
}
