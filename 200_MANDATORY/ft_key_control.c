/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:51:52 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 14:51:52 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

int	ft_key_control(t_gobj *game)
{
	int	moveable;

	moveable = !(game->p1->finish);
	if (game->keys_state[XK_Escape])
		ft_end(game, 1);
	if (game->keys_state[XK_w] && !game->keys_state[XK_s] && moveable)
		ft_move_plr_n(game, game->p1);
	else if (game->keys_state[XK_a] && !game->keys_state[XK_d] && moveable)
		ft_move_plr_w(game, game->p1);
	else if (game->keys_state[XK_s] && !game->keys_state[XK_w] && moveable)
		ft_move_plr_s(game, game->p1);
	else if (game->keys_state[XK_d] && !game->keys_state[XK_a] && moveable)
		ft_move_plr_e(game, game->p1);
	return (0);
}
