/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:20:11 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/16 17:20:13 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_paint_floor(t_gobj *game, t_player *plr)
{
	if (game->str.map[plr->j / 32][plr->i / 32] == '0' && plr->exit == '#')
		game->str.map[plr->j / 32][plr->i / 32] = '-';
	if (game->str.map[(plr->j + 15) / 32][plr->i / 32] == '0' && plr->exit == '#')
		game->str.map[(plr->j + 15) / 32][plr->i / 32] = '-';
	if (game->str.map[plr->j / 32][(plr->i + 15) / 32] == '0' && plr->exit == '#')
		game->str.map[plr->j / 32][(plr->i + 15) / 32] = '-';
	if (game->str.map[(plr->j + 15) / 32][(plr->i + 15) / 32] == '0' && plr->exit == '#')
		game->str.map[(plr->j + 15) / 32][(plr->i + 15) / 32] = '-';
	if (game->str.map[plr->j / 32][plr->i / 32] == '-' && plr->exit == 'E')
		game->str.map[plr->j / 32][plr->i / 32] = '0';
	if (game->str.map[(plr->j + 15) / 32][plr->i / 32] == '-' && plr->exit == 'E')
		game->str.map[(plr->j + 15) / 32][plr->i / 32] = '0';
	if (game->str.map[plr->j / 32][(plr->i + 15) / 32] == '-' && plr->exit == 'E')
		game->str.map[plr->j / 32][(plr->i + 15) / 32] = '0';
	if (game->str.map[(plr->j + 15) / 32][(plr->i + 15) / 32] == '-' && plr->exit == 'E')
		game->str.map[(plr->j + 15) / 32][(plr->i + 15) / 32] = '0';
}
