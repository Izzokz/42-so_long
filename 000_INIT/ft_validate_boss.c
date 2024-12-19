/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_boss.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:05:00 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/19 15:58:00 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_boss(t_gobj *game)
{
	t_ints	t;

	if (!game->enemies)
		return ;
	t.i = -1;
	t.count = 0;
	t.count1 = 0;
	while (game->enemies[++(t.i)])
	{
		if (game->enemies[t.i]->type == 'b')
		{
			game->p3 = game->enemies[t.i];
			t.count++;
		}
		if (game->enemies[t.i]->type == 'B')
			t.count1++;
	}
	if (t.count > 1 || t.count1 > 1)
	{
		ft_printf("It seems to be too much bosses...\n");
		ft_printf("You can add a maximum of one 'b' and one 'B' per map.\n");
		ft_end(game, -1);
	}
}
