/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:16:43 by psoares-          #+#    #+#             */
/*   Updated: 2022/11/05 18:51:15 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*auxiliar;

	if (!*lst)
		return ;
	while (*lst)
	{
		auxiliar = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = auxiliar;
	}
	free(*lst);
}
