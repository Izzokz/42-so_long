/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:45:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/05 10:45:25 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	valid_move(t_gobj *game, int pi, int pj)
{
	return (game->str.map[pj / 32][pi / 32] != '1'
		&& game->str.map[(pj + 15) / 32][pi / 32] != '1'
		&& game->str.map[pj / 32][(pi + 15) / 32] != '1'
		&& game->str.map[(pj + 15) / 32][(pi + 15) / 32] != '1');
}

int	ft_move_player_n(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (valid_move(game, game->p1->i, game->p1->j - speed))
		{
			game->p1->j -= speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	ft_exit_area(game, &(game->p1));
	return (speed);
}

int	ft_move_player_s(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (valid_move(game, game->p1->i, game->p1->j + speed))
		{
			game->p1->j += speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	ft_exit_area(game, &(game->p1));
	return (speed);
}

int	ft_move_player_w(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (valid_move(game, game->p1->i - speed, game->p1->j))
		{
			game->p1->i -= speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	ft_exit_area(game, &(game->p1));
	return (speed);
}

int	ft_move_player_e(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (valid_move(game, game->p1->i + speed, game->p1->j))
		{
			game->p1->i += speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	ft_exit_area(game, &(game->p1));
	return (speed);
}
