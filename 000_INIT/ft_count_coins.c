/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_coins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:24:46 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:42:53 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_coins(t_gobj *game, char coin_id)
{
	t_ints	i;

	i.count = 0;
	i.i = -1;
	while (game->str.map[++(i.i)])
	{
		i.j = -1;
		while (game->str.map[i.i][++(i.j)])
			if (game->str.map[i.i][i.j] == coin_id)
				(i.count)++;
	}
	return (i.count);
}
