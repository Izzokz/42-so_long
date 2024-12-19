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

static void	change_plr_spd(t_gobj *game, int val)
{
	static int	plr_s1 = 0;
	static int	plr_s2 = 0;

	if (game->p1->spd != 0)
		plr_s1 = game->p1->spd;
	if (game->p2->spd != 0)
		plr_s2 = game->p2->spd;
	if (val == 69 && plr_s1 != 0 && plr_s2 != 0)
	{
		game->p1->spd = plr_s1;
		game->p2->spd = plr_s2;
		return ;
	}
	game->p1->spd = val;
	game->p2->spd = val;
}

int	summon_enemy(t_gobj *game, int i, int j)
{
	int	rand;

	if (j <= 0 || j >= game->height * 32
		|| i <= 0 || i >= game->width * 32)
		return (0);
	if (!is_valid_move(game, i, j))
		return (0);
	rand = ft_random(4);
	if (rand == 1)
		ft_create_enemy(game, 'Q', j / 32, i / 32);
	else if (rand == 2)
		ft_create_enemy(game, 'M', j / 32, i / 32);
	else if (rand == 3)
		ft_create_enemy(game, 'H', j / 32, i / 32);
	else
		ft_create_enemy(game, 'h', j / 32, i / 32);
	return (1);
}

static void	init_shoot(t_gobj *game, int i, int j)
{
	if (j <= 0 || j >= game->height * 32
		|| i <= 0 || i >= game->width * 32)
		return ;
	game->str.map[j / 32][i / 32] = '*';
	ft_update_tile(game, j / 32, i / 32);
}

static void	annihilate(t_gobj *game, int i, int j)
{
	if (game->str.map[game->p1->j / 32][game->p1->i / 32] == '*'
		|| game->str.map[(game->p1->j + 15) / 32][game->p1->i / 32] == '*'
		|| game->str.map[game->p1->j / 32][(game->p1->i + 15) / 32] == '*'
		|| game->str.map[(game->p1->j + 15) / 32][(game->p1->i + 15) / 32]
			== '*')
	{
		game->p1->finish = -1;
		ft_restart(game, 1);
	}
	if (game->str.map[game->p2->j / 32][game->p2->i / 32] == '*'
		|| game->str.map[(game->p2->j + 15) / 32][game->p2->i / 32] == '*'
		|| game->str.map[game->p2->j / 32][(game->p2->i + 15) / 32] == '*'
		|| game->str.map[(game->p2->j + 15) / 32][(game->p2->i + 15) / 32]
			== '*')
	{
		game->p2->finish = -1;
		ft_restart(game, 1);
	}
	game->str.map[j / 32][i / 32] = '0';
	ft_update_tile(game, j / 32, i / 32);
}

void	ft_boss_action(t_gobj *game, t_enemy *ene, t_player *plr)
{
	static t_ints	t;

	if (ene->ticks % 2)
		return ;
	if (ene->ticks % 500 == 60 || ene->ticks % 500 == 90
		|| ene->ticks % 500 == 120 || ene->ticks % 500 == 160)
	{
		if (ene->ticks % 500 > 60)
			annihilate(game, t.i, t.j);
		if (ene->ticks % 500 < 160)
		{
			init_shoot(game, plr->i, plr->j);
			t.i = plr->i;
			t.j = plr->j;
		}
	}
	if (ene->ticks % 200 == 0)
		summon_enemy(game, ene->i, ene->j);
	if (ene->ticks % 100 == 0)
		change_plr_spd(game, 0);
	if (ene->ticks % 100 == 16)
		change_plr_spd(game, 69);
	if (ft_random(100) == 100)
		change_plr_spd(game, 1);
}
