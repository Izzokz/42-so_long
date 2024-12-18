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

static int	does_kill_plr(t_enemy *ene, t_player *plr)
{
	return (abs(ene->i - plr->i) < 16 && abs(ene->j - plr->j) < 16);
}

static void	validate_move(t_gobj *gm, t_enemy *ene, int i, int j)
{
	if (is_valid_move(gm, ene->i + i, ene->j + j))
	{
		ene->i += i;
		ene->j += j;
	}
	else if (!(ene->q_pass % 3 - 1))
	{
		ene->i += i;
		ene->j += j;
	}
}

static void	move_toward_plr(t_gobj *game, t_enemy *ene, t_player *plr)
{
	int	i_diff;
	int	j_diff;

	if (!plr)
		return ;
	i_diff = ene->i - plr->i;
	j_diff = ene->j - plr->j;
	if (ene->type == 'q')
		ene->q_pass++;
	ene->ticks++;
	if (ene->type == 'H' && ene->ticks % 120 == 0)
		return (ft_teleport(game, ene, plr));
	if (i_diff < 0)
		validate_move(game, ene, ene->spd, 0);
	else if (i_diff > 0)
		validate_move(game, ene, -(ene->spd), 0);
	if (j_diff < 0)
		validate_move(game, ene, 0, ene->spd);
	else if (j_diff > 0)
		validate_move(game, ene, 0, -(ene->spd));
}

static t_player	*nearest_plr(t_gobj *game, int i, int j)
{
	int	dist_p1;
	int	dist_p2;

	if (game->p2->finish)
		return (game->p1);
	if (game->p1->finish)
		return (game->p2);
	dist_p1 = abs(i - game->p1->i) + abs(j - game->p1->j);
	dist_p2 = abs(i - game->p2->i) + abs(j - game->p2->j);
	if (dist_p1 < dist_p2)
		return (game->p1);
	if (dist_p1 > dist_p2)
		return (game->p2);
	return (NULL);
}

void	ft_move_enemies(t_gobj *game)
{
	static int	skip = 0;
	int			i;

	skip += 1;
	if (!game->enemies || skip % 6)
		return ;
	i = -1;
	while (game->enemies[++i])
	{
		if (ft_merge_from(game, game->enemies[i], i))
			break ;
		move_toward_plr(game, game->enemies[i],
			nearest_plr(game, game->enemies[i]->i, game->enemies[i]->j));
		if (does_kill_plr(game->enemies[i], game->p1))
		{
			game->p1->finish = -1;
			ft_restart(game, 1);
		}
		if (does_kill_plr(game->enemies[i], game->p2))
		{
			game->p2->finish = -1;
			ft_restart(game, 1);
		}
		ft_update_dmap(game, game->enemies[i]->i, game->enemies[i]->j);
	}
}
