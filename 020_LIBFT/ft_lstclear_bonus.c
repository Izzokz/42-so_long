/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:55:06 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/15 14:55:07 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*temp;

	if (!list || !(*list) || !del)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		ft_lstdelone(*list, del);
		*list = temp;
	}
	*list = NULL;
}
