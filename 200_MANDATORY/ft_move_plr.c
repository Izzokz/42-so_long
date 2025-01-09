/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:27:33 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/07 15:27:34 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static int	ft_collect(t_gobj *game, int pi, int pj)
{
	if (game->map[pj][pi] == 'C')
	{
		game->map[pj][pi] = '0';
		return (1);
	}
	return (0);
}

void	ft_move_plr_n(t_gobj *game, t_player *plr)
{
	if (game->map[plr->j - 1][plr->i] == '1')
		return ;
	plr->j--;
	plr->coin_count -= ft_collect(game, plr->i, plr->j);
	if (plr->moves + 1 >= 0)
		ft_printf("Moves: %i\n", ++(plr->moves));
	else
		ft_printf("Moves capped: INT_MAX\n");
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i, plr->j + 1);
}

void	ft_move_plr_s(t_gobj *game, t_player *plr)
{
	if (game->map[plr->j + 1][plr->i] == '1')
		return ;
	plr->j++;
	plr->coin_count -= ft_collect(game, plr->i, plr->j);
	if (plr->moves + 1 >= 0)
		ft_printf("Moves: %i\n", ++(plr->moves));
	else
		ft_printf("Moves capped: INT_MAX\n");
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i, plr->j - 1);
}

void	ft_move_plr_w(t_gobj *game, t_player *plr)
{
	if (game->map[plr->j][plr->i - 1] == '1')
		return ;
	plr->i--;
	plr->coin_count -= ft_collect(game, plr->i, plr->j);
	if (plr->moves + 1 >= 0)
		ft_printf("Moves: %i\n", ++(plr->moves));
	else
		ft_printf("Moves capped: INT_MAX\n");
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i + 1, plr->j);
}

void	ft_move_plr_e(t_gobj *game, t_player *plr)
{
	if (game->map[plr->j][plr->i + 1] == '1')
		return ;
	plr->i++;
	plr->coin_count -= ft_collect(game, plr->i, plr->j);
	if (plr->moves + 1 >= 0)
		ft_printf("Moves: %i\n", ++(plr->moves));
	else
		ft_printf("Moves capped: INT_MAX\n");
	ft_exit_area(game, &plr);
	ft_update_dmap(game, plr->i - 1, plr->j);
}
