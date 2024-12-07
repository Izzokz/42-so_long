/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_area.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:21:10 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 13:21:11 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit_area(t_gobj *game, t_player **player)
{
	int		pi;
	int		pj;
	char	exit_id;

	pi = (*player)->i;
	pj = (*player)->j;
	exit_id = (*player)->exit;
	if ((game->str.map[pj / 32][pi / 32] == exit_id
		|| game->str.map[(pj + 15) / 32][pi / 32] == exit_id
		|| game->str.map[pj / 32][(pi + 15) / 32] == exit_id
		|| game->str.map[(pj + 15) / 32][(pi + 15) / 32] == exit_id)
		&& (*player)->coin_count == 0)
	{
		(*player)->finish = 1;
		(game->player_count)--;
	}
}
