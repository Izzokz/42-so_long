/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:48:45 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/15 12:48:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new_node)
{
	if (!list || !new_node)
		return ;
	if (!(*list))
		*list = new_node;
	else
		ft_lstlast(*list)->next = new_node;
}
