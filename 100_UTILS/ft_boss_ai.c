/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boss_ai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:36:48 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/03/18 17:36:49 by kzhen-cl         ###   ########.fr       */
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

static void	ft_boss_action2(t_gobj *game, t_enemy *ene, t_player *plr)
{
	int						rand;
	static t_fiveposbits	i = (t_fiveposbits){-32};
	static float			init_theme;

	rand = ft_random(200);
	if (i.fb >= 0)
	{
		if (i.fb == 0)
			init_theme = game->theme;
		if (++i.fb <= 31 && i.fb > 0)
			game->theme = (float)i.fb * (1.0f / 32.0f);
		else
		{
			game->theme = init_theme;
			ft_print_map(game);
		}
	}
	if (rand == 200)
		change_plr_spd(plr, 1);
	else if (rand == 42 && i.fb < 0)
		i.fb = 0;
	if (ene->ticks % 200 == 0)
		summon_enemy(game, ene->i / 32, ene->j / 32);
}

void	ft_boss_action(t_gobj *game, t_enemy *ene, t_player *plr)
{
	if (ene->ticks % 2)
		return ;
	if (ene->ticks % 500 == 60 || ene->ticks % 500 == 90
		|| ene->ticks % 500 == 120 || ene->ticks % 500 == 150)
	{
		if (ene->ticks % 500 > 60)
			annihilate(game, ene->t_i, ene->t_j, &ene);
		if (ene->ticks % 500 < 150)
		{
			init_shoot(game, plr->i, plr->j);
			ene->t_i = plr->i;
			ene->t_j = plr->j;
		}
	}
	if (ene->ticks % 100 == 0)
	{
		change_plr_spd(game->p1, 0);
		change_plr_spd(game->p2, 0);
	}
	if (ene->ticks % 100 == 16)
	{
		change_plr_spd(game->p2, 69);
		change_plr_spd(game->p1, 69);
	}
	return (ft_boss_action2(game, ene, plr));
}
