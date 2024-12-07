/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:22:00 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/16 12:22:01 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_node;

	if (!list || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(list->content));
	if (!new_list)
		return (NULL);
	list = list->next;
	while (list)
	{
		next_node = ft_lstnew(f(list->content));
		if (!next_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, next_node);
		list = list->next;
	}
	return (new_list);
}
