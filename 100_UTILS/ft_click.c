/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_click.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:59 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/19 16:52:44 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	plr_too_close(t_gobj *game, int x, int y)
{
	if (!(game->p1->finish)
		&& abs(game->p1->i - x) < 64 && abs(game->p1->j - y) < 64)
		return (1);
	if (!(game->p2->finish)
		&& abs(game->p2->i - x) < 64 && abs(game->p2->j - y) < 64)
		return (1);
	return (0);
}

static void	fire_laser(t_gobj *game)
{
	if (game->p3->ticks > 30)
	{
		annihilate(game, game->p3->t_i, game->p3->t_j);
		game->p3->t_i = 0;
		game->p3->t_j = 0;
	}
}

int	ft_click(int button, int x, int y, t_gobj *game)
{
	if (!game->p3)
		return (0);
	x -= (game->win_i - game->width * 32) / 2;
	if (game->p3->t_i != 0 || game->p3->t_j != 0)
		fire_laser(game);
	if (button == 1 && game->p3->ticks > 750)
	{
		if (!plr_too_close(game, x, y) && summon_enemy(game, x / 32, y / 32))
			game->p3->ticks = 0;
	}
	else if (game->p3->ticks > 750)
	{
		if (game->str.map[y / 32][x / 32] == '0'
			|| game->str.map[y / 32][x / 32] == '-')
		{
			init_shoot(game, x, y);
			game->p3->t_i = x;
			game->p3->t_j = y;
			game->p3->ticks = 0;
		}
	}
	return (0);
}
