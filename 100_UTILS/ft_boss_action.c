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

static void	annihilate_enemies(t_gobj *game, int i, int j)
{
	int		x[3];
	t_enemy	*e;

	*x = -1;
	while (*(game->enemies + ++(*x)))
	{
		e = *(game->enemies + *x);
		if (e->type == 'b' || e->type == 'B')
			continue ;
		if ((e->i / 32 == i / 32 && e->j / 32 == j / 32)
			|| ((e->i + 15) / 32 == i / 32 && e->j / 32 == j / 32)
			|| (e->i / 32 == i / 32 && (e->j + 15) / 32 == j / 32)
			|| ((e->i + 15) / 32 == i / 32
				&& (e->j + 15) / 32 == j / 32))
		{
			*(x + 1) = e->i;
			*(x + 2) = e->j;
			if (ft_dealloc_enemies(game, *x) == -1)
				ft_end(game, ft_printf("so_long:ft_boss_action.c:65:\
ft_dealloc_enemies(%*.) [fail]\n"));
			ft_validate_boss(game);
			ft_update_dmap(game, *(x + 1), *(x + 2));
			(*x)--;
		}
	}
}

static t_enemy	*get_boss(t_gobj *game, char type)
{
	int	i;

	i = -1;
	while (*(game->enemies + ++i))
	{
		if ((*(game->enemies + i))->type == type)
			return (*(game->enemies + i));
	}
	return (NULL);
}

void	annihilate(t_gobj *g, int i, int j, t_enemy **ene)
{
	char	type;

	if (!g->p1->finish && ((g->p1->i / 32 == i / 32 && g->p1->j / 32 == j / 32)
			|| ((g->p1->i + 15) / 32 == i / 32 && g->p1->j / 32 == j / 32)
			|| (g->p1->i / 32 == i / 32 && (g->p1->j + 15) / 32 == j / 32)
			|| ((g->p1->i + 15) / 32 == i / 32
				&& (g->p1->j + 15) / 32 == j / 32)))
	{
		g->p1->finish = -1;
		ft_restart(g, 1);
	}
	if (!g->p2->finish && ((g->p2->i / 32 == i / 32 && g->p2->j / 32 == j / 32)
			|| ((g->p2->i + 15) / 32 == i / 32 && g->p2->j / 32 == j / 32)
			|| (g->p2->i / 32 == i / 32 && (g->p2->j + 15) / 32 == j / 32)
			|| ((g->p2->i + 15) / 32 == i / 32
				&& (g->p2->j + 15) / 32 == j / 32)))
	{
		g->p2->finish = -1;
		ft_restart(g, 1);
	}
	g->str.map[j / 32][i / 32] = '0';
	type = (*ene)->type;
	annihilate_enemies(g, i, j);
	*ene = get_boss(g, type);
	ft_update_tile(g, j / 32, i / 32);
}
