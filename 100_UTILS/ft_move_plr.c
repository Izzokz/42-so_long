/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:45:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/12 17:05:05 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_move(t_gobj *game, int pi, int pj)
{
	return (game->str.map[pj / 32][pi / 32] != '1'
		&& game->str.map[(pj + 15) / 32][pi / 32] != '1'
		&& game->str.map[pj / 32][(pi + 15) / 32] != '1'
		&& game->str.map[(pj + 15) / 32][(pi + 15) / 32] != '1'
		&& game->str.map[pj / 32][pi / 32] != '+'
		&& game->str.map[(pj + 15) / 32][pi / 32] != '+'
		&& game->str.map[pj / 32][(pi + 15) / 32] != '+'
		&& game->str.map[(pj + 15) / 32][(pi + 15) / 32] != '+'
		&& ((game->str.map[pj / 32][pi / 32] != '!'
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

void	ft_move_plr_n(t_gobj *game, t_player *plr)
{
	int	speed;

	speed = (int)(plr->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, plr->i, plr->j - speed))
		{
			plr->j -= speed;
			break ;
		}
	}
	if (plr->exit == 'E')
		plr->coin_count -= ft_collect(game, plr->i, plr->j);
	else
		plr->coin_count -= ft_collect2(game, plr->i, plr->j);
	plr->moves += speed;
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i, plr->j);
	ft_print_stats(game);
}

void	ft_move_plr_s(t_gobj *game, t_player *plr)
{
	int	speed;

	speed = (int)(plr->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, plr->i, plr->j + speed))
		{
			plr->j += speed;
			break ;
		}
	}
	if (plr->exit == 'E')
		plr->coin_count -= ft_collect(game, plr->i, plr->j);
	else
		plr->coin_count -= ft_collect2(game, plr->i, plr->j);
	plr->moves += speed;
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i, plr->j);
	ft_print_stats(game);
}

void	ft_move_plr_w(t_gobj *game, t_player *plr)
{
	int	speed;

	speed = (int)(plr->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, plr->i - speed, plr->j))
		{
			plr->i -= speed;
			break ;
		}
	}
	if (plr->exit == 'E')
		plr->coin_count -= ft_collect(game, plr->i, plr->j);
	else
		plr->coin_count -= ft_collect2(game, plr->i, plr->j);
	plr->moves += speed;
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i, plr->j);
	ft_print_stats(game);
}

void	ft_move_plr_e(t_gobj *game, t_player *plr)
{
	int	speed;

	speed = (int)(plr->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, plr->i + speed, plr->j))
		{
			plr->i += speed;
			break ;
		}
	}
	if (plr->exit == 'E')
		plr->coin_count -= ft_collect(game, plr->i, plr->j);
	else
		plr->coin_count -= ft_collect2(game, plr->i, plr->j);
	plr->moves += speed;
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i, plr->j);
	ft_print_stats(game);
}
