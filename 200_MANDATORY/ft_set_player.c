/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:03 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/07 17:42:04 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

void	ft_set_player(t_gobj *game)
{
	t_ints	i;

	i.x = -1;
	while (game->map[++(i.x)])
	{
		i.y = -1;
		while (game->map[i.x][++(i.y)])
		{
			if (game->map[i.x][i.y] == 'P')
			{
				game->p1->i = i.y;
				game->p1->j = i.x;
				game->map[i.x][i.y] = '0';
			}
		}
	}
}
