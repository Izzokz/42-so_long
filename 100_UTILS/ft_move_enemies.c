/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:14:13 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/16 16:14:14 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	does_kill_player(t_enemy *ene, t_player *plr)
{
	return (abs(ene->i - plr->i) < 16 && abs(ene->j - plr->j) < 16);
}

int	ft_move_enemies(t_gobj *game)
{
	int	i;

	if (!game->enemies)
		return (0);
	i = -1;
	while (game->enemies[++i])
	{
		if (does_kill_player(game->enemies[i], game->p1))
		{
			game->p1->finish = -1;
			ft_restart(game, 1);
		}
		if (does_kill_player(game->enemies[i], game->p2))
		{
			game->p2->finish = -1;
			ft_restart(game, 1);
		}
	}
	return (0);
}
