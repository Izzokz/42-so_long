/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boss_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:28:16 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/19 11:28:17 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	change_plr_spd(t_player *plr, int val)
{
	static int	plr_s1 = 0;
	static int	plr_s2 = 0;

	if (plr->exit == 'E' && plr->spd != 0)
		plr_s1 = plr->spd;
	if (plr->exit == '#' && plr->spd != 0)
		plr_s2 = plr->spd;
	if (plr->exit == 'E' && val == 69 && plr_s1 != 0)
	{
		plr->spd = plr_s1;
		return ;
	}
	if (plr->exit == '#' && val == 69 && plr_s2 != 0)
	{
		plr->spd = plr_s2;
		return ;
	}
	plr->spd = val;
}

int	summon_enemy(t_gobj *gm, int i, int j)
{
	int	rand;

	if (j <= 0 || j >= gm->height
		|| i <= 0 || i >= gm->width)
		return (0);
	if (gm->str.map[j][i] != '0' && gm->str.map[j][i] != '-')
		return (0);
	rand = ft_random(4);
	if (rand == 1)
		ft_create_enemy(gm, 'Q', j, i);
	else if (rand == 2)
		ft_create_enemy(gm, 'M', j, i);
	else if (rand == 3)
		ft_create_enemy(gm, 'H', j, i);
	else
		ft_create_enemy(gm, 'h', j, i);
	ft_validate_boss(gm);
	return (1);
}

void	init_shoot(t_gobj *game, int i, int j)
{
	if (j <= 0 || j >= game->height * 32
		|| i <= 0 || i >= game->width * 32)
		return ;
	game->str.map[j / 32][i / 32] = '*';
	ft_update_tile(game, j / 32, i / 32);
}

void	annihilate(t_gobj *g, int i, int j)
{
	if (!g->p1->finish && ((g->p1->i / 32 == i / 32 && g->p1->j / 32 == j / 32)
			|| (g->p1->i / 32 + 1 == i / 32 && g->p1->j / 32 == j / 32)
			|| (g->p1->i / 32 == i / 32 && g->p1->j / 32 + 1 == j / 32)
			|| (g->p1->i / 32 + 1 == i / 32
				&& g->p1->j / 32 + 1 == j / 32)))
	{
		g->p1->finish = -1;
		ft_restart(g, 1);
	}
	if (!g->p2->finish && ((g->p2->i / 32 == i / 32 && g->p2->j / 32 == j / 32)
			|| (g->p2->i / 32 + 1 == i / 32 && g->p2->j / 32 == j / 32)
			|| (g->p2->i / 32 == i / 32 && g->p2->j / 32 + 1 == j / 32)
			|| (g->p2->i / 32 + 1 == i / 32
				&& g->p2->j / 32 + 1 == j / 32)))
	{
		g->p2->finish = -1;
		ft_restart(g, 1);
	}
	g->str.map[j / 32][i / 32] = '0';
	ft_update_tile(g, j / 32, i / 32);
}

void	ft_boss_action(t_gobj *game, t_enemy *ene, t_player *plr)
{
	if (ene->ticks % 2)
		return ;
	if (ene->ticks % 500 == 60 || ene->ticks % 500 == 90
		|| ene->ticks % 500 == 120 || ene->ticks % 500 == 160)
	{
		if (ene->ticks % 500 > 60)
			annihilate(game, ene->t_i, ene->t_j);
		if (ene->ticks % 500 < 160)
		{
			init_shoot(game, plr->i, plr->j);
			ene->t_i = plr->i;
			ene->t_j = plr->j;
		}
	}
	if (ene->ticks % 100 == 0)
		change_plr_spd(plr, 0);
	if (ene->ticks % 100 == 16)
		change_plr_spd(plr, 69);
	if (ft_random(200) == 200)
		change_plr_spd(plr, 1);
	if (ene->ticks % 200 == 0)
		summon_enemy(game, ene->i / 32, ene->j / 32);
}
