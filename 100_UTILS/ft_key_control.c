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

static void	ft_key_control2(t_gobj *game)
{
	int	moveable;

	moveable = !(game->p2->finish);
	if (game->keys_state[XK_Up] && !game->keys_state[XK_Down] && moveable)
		ft_move_p2_n(game);
	if (game->keys_state[XK_Left] && !game->keys_state[XK_Right] && moveable)
		ft_move_p2_w(game);
	if (game->keys_state[XK_Right] && !game->keys_state[XK_Left] && moveable)
		ft_move_p2_e(game);
	if (game->keys_state[XK_Down] && !game->keys_state[XK_Up] && moveable)
		ft_move_p2_s(game);
}

int	ft_key_control(t_gobj *game)
{
	static float	time_to_fps = 0.0f;
	int				moveable;

	time_to_fps += ft_delta_time();
	while (time_to_fps >= (1.0f / FPS))
	{
		moveable = !(game->p1->finish);
		time_to_fps -= (1.0f / FPS);
		if (game->keys_state[XK_Escape])
			ft_quit_game(game);
		if (game->keys_state[XK_w] && !game->keys_state[XK_s] && moveable)
			ft_move_p1_n(game);
		if (game->keys_state[XK_a] && !game->keys_state[XK_d] && moveable)
			ft_move_p1_w(game);
		if (game->keys_state[XK_s] && !game->keys_state[XK_w] && moveable)
			ft_move_p1_s(game);
		if (game->keys_state[XK_d] && !game->keys_state[XK_a] && moveable)
			ft_move_p1_e(game);
		ft_key_control2(game);
	}
	return (0);
}
