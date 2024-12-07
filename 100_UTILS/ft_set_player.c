/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:32 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/05 11:26:34 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_set_player(t_gobj *game)
{
	t_ints		i;

	i.x = -1;
	while (game->str.map[++(i.x)])
	{
		i.y = -1;
		while (game->str.map[i.x][++(i.y)])
		{
			if (game->str.map[i.x][i.y] == 'P')
			{
				game->p1->i = i.y * 32 + 8;
				game->p1->j = i.x * 32 + 8;
				game->str.map[i.x][i.y] = '0';
				return ;
			}
		}
	}
}
