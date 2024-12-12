/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlock_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:21:56 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/12 13:21:58 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <math.h>

static int	not_locked(t_gobj *game, int pi, int pj)
{
	return (((game->str.map[pj / 32][pi / 32] != '!'
		&& game->str.map[(pj + 15) / 32][pi / 32] != '!'
		&& game->str.map[pj / 32][(pi + 15) / 32] != '!'
		&& game->str.map[(pj + 15) / 32][(pi + 15) / 32] != '!')
		|| (game->p1->coin_count + game->p2->coin_count) % 2 == 0)
		&& ((game->str.map[pj / 32][pi / 32] != '?'
		&& game->str.map[(pj + 15) / 32][pi / 32] != '?'
		&& game->str.map[pj / 32][(pi + 15) / 32] != '?'
		&& game->str.map[(pj + 15) / 32][(pi + 15) / 32] != '?')
		|| (game->p1->coin_count + game->p2->coin_count) % 2));
}

static void	get_safe_pos2(t_gobj *gm, t_player *plr, char direc)
{
	if (direc == 'w')
	{
		while (!is_valid_move(gm, plr->i, plr->j))
		{
			(plr->i)--;
			ft_update_dmap(gm, plr->i, plr->j);
		}
		return ;
	}
	while (!is_valid_move(gm, plr->i, plr->j))
	{
		(plr->i)++;
		ft_update_dmap(gm, plr->i, plr->j);
	}
}

static void	get_safe_pos(t_gobj *gm, t_player *plr, char direc)
{
	if (direc == 'n')
	{
		while (!is_valid_move(gm, plr->i, plr->j))
		{
			(plr->j)--;
			ft_update_dmap(gm, plr->i, plr->j);
		}
		return ;
	}
	else if (direc == 's')
	{
		while (!is_valid_move(gm, plr->i, plr->j))
		{
			(plr->j)++;
			ft_update_dmap(gm, plr->i, plr->j);
		}
		return ;
	}
	return (get_safe_pos2(gm, plr, direc));
}

void	ft_unlock_player(t_gobj *game, t_player *plr)
{
	if (not_locked(game, plr->i, plr->j))
		return ;
	if (is_valid_move(game, plr->i, plr->j - 32))
		return (get_safe_pos(game, plr, 'n'));
	if (is_valid_move(game, plr->i, plr->j + 32))
		return (get_safe_pos(game, plr, 's'));
	if (is_valid_move(game, plr->i - 32, plr->j))
		return (get_safe_pos(game, plr, 'w'));
	return (get_safe_pos(game, plr, 'w'));
}
