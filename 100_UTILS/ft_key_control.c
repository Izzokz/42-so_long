/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:30:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 13:17:48 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_key_control(t_gobj *game)
{
	static float	time_to_fps = 0.0f;
	float			delta_time;
	int				moveable;

	delta_time = ft_delta_time();
	time_to_fps += delta_time;
	while (time_to_fps >= (1.0f / FPS))
	{
		moveable = !(game->p1->finish);
		time_to_fps -= (1.0f / FPS);
		if (game->keys_state[XK_Escape])
			ft_quit_game(game);
		if (game->keys_state[XK_w] && !game->keys_state[XK_s] && moveable)
			game->p1->moves += ft_move_player_n(game);
		if (game->keys_state[XK_a] && !game->keys_state[XK_d] && moveable)
			game->p1->moves += ft_move_player_w(game);
		if (game->keys_state[XK_s] && !game->keys_state[XK_w] && moveable)
			game->p1->moves += ft_move_player_s(game);
		if (game->keys_state[XK_d] && !game->keys_state[XK_a] && moveable)
			game->p1->moves += ft_move_player_e(game);
		ft_print_map(game);
	}
	ft_print_stats(game);
	return (0);
}
