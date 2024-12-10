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

int	is_valid_move(t_gobj *game, int pi, int pj)
{
	return (game->str.map[pj / 32][pi / 32] != '1'
		&& game->str.map[(pj + 15) / 32][pi / 32] != '1'
		&& game->str.map[pj / 32][(pi + 15) / 32] != '1'
		&& game->str.map[(pj + 15) / 32][(pi + 15) / 32] != '1'
		&& game->str.map[pj / 32][pi / 32] != '+'
		&& game->str.map[(pj + 15) / 32][pi / 32] != '+'
		&& game->str.map[pj / 32][(pi + 15) / 32] != '+'
		&& game->str.map[(pj + 15) / 32][(pi + 15) / 32] != '+');
}

void	ft_move_p1_n(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p1->i, game->p1->j - speed))
		{
			game->p1->j -= speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	game->p1->moves += speed;
	ft_exit_area(game, &(game->p1));
	ft_update_dmap(game, game->p1->i, game->p1->j);
	ft_print_stats(game);
}

void	ft_move_p1_s(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p1->i, game->p1->j + speed))
		{
			game->p1->j += speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	game->p1->moves += speed;
	ft_exit_area(game, &(game->p1));
	ft_update_dmap(game, game->p1->i, game->p1->j);
	ft_print_stats(game);
}

void	ft_move_p1_w(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p1->i - speed, game->p1->j))
		{
			game->p1->i -= speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	game->p1->moves += speed;
	ft_exit_area(game, &(game->p1));
	ft_update_dmap(game, game->p1->i, game->p1->j);
	ft_print_stats(game);
}

void	ft_move_p1_e(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p1->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p1->i + speed, game->p1->j))
		{
			game->p1->i += speed;
			break ;
		}
	}
	game->p1->coin_count -= ft_collect(game, game->p1->i, game->p1->j);
	game->p1->moves += speed;
	ft_exit_area(game, &(game->p1));
	ft_update_dmap(game, game->p1->i, game->p1->j);
	ft_print_stats(game);
}
