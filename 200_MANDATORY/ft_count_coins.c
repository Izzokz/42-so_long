/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_coins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:47:35 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 13:47:36 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

int	ft_count_coins(t_gobj *game)
{
	t_ints	i;

	i.count = 0;
	i.i = -1;
	while (game->map[++(i.i)])
	{
		i.j = -1;
		while (game->map[i.i][++(i.j)])
			if (game->map[i.i][i.j] == 'C')
				(i.count)++;
	}
	return (i.count);
}
