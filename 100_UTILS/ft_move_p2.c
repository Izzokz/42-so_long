/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:13:35 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/10 16:13:37 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_p2_n(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p2->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p2->i, game->p2->j - speed))
		{
			game->p2->j -= speed;
			break ;
		}
	}
	game->p2->coin_count -= ft_collect2(game, game->p2->i, game->p2->j);
	game->p2->moves += speed;
	ft_exit_area(game, &(game->p2));
	ft_update_dmap(game, game->p2->i, game->p2->j);
	ft_print_stats(game);
}

void	ft_move_p2_s(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p2->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p2->i, game->p2->j + speed))
		{
			game->p2->j += speed;
			break ;
		}
	}
	game->p2->coin_count -= ft_collect2(game, game->p2->i, game->p2->j);
	game->p2->moves += speed;
	ft_exit_area(game, &(game->p2));
	ft_update_dmap(game, game->p2->i, game->p2->j);
	ft_print_stats(game);
}

void	ft_move_p2_w(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p2->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p2->i - speed, game->p2->j))
		{
			game->p2->i -= speed;
			break ;
		}
	}
	game->p2->coin_count -= ft_collect2(game, game->p2->i, game->p2->j);
	game->p2->moves += speed;
	ft_exit_area(game, &(game->p2));
	ft_update_dmap(game, game->p2->i, game->p2->j);
	ft_print_stats(game);
}

void	ft_move_p2_e(t_gobj *game)
{
	int	speed;

	speed = (int)(game->p2->spd + 1.0f);
	while (--speed > 0)
	{
		if (is_valid_move(game, game->p2->i + speed, game->p2->j))
		{
			game->p2->i += speed;
			break ;
		}
	}
	game->p2->coin_count -= ft_collect2(game, game->p2->i, game->p2->j);
	game->p2->moves += speed;
	ft_exit_area(game, &(game->p2));
	ft_update_dmap(game, game->p2->i, game->p2->j);
	ft_print_stats(game);
}
