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

static void	ft_refresh_window(t_gobj *game)
{
	ft_change_screen_form(game);
	ft_print_map(game);
}

static void	ft_brightness(t_gobj *game)
{
	float	tmp;

	tmp = game->brn;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_0])
		game->brn = 1.0f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_1])
		game->brn = 0.1f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_2])
		game->brn = 0.2f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_3])
		game->brn = 0.3f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_4])
		game->brn = 0.4f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_5])
		game->brn = 0.5f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_6])
		game->brn = 0.6f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_7])
		game->brn = 0.7f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_8])
		game->brn = 0.8f;
	if (game->keys_state[XK_Control_L] && game->keys_state[XK_9])
		game->brn = 0.9f;
	if (game->brn != tmp)
		ft_refresh_window(game);
}

static void	ft_theme(t_gobj *game)
{
	float	tmp;

	tmp = game->theme;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_0])
		game->theme = 1.0f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_1])
		game->theme = 0.1f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_2])
		game->theme = 0.2f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_3])
		game->theme = 0.3f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_4])
		game->theme = 0.4f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_5])
		game->theme = 0.5f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_6])
		game->theme = 0.6f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_7])
		game->theme = 0.7f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_8])
		game->theme = 0.8f;
	if (game->keys_state[XK_Control_R] && game->keys_state[XK_9])
		game->theme = 0.9f;
	if (game->theme != tmp)
		ft_refresh_window(game);
}

static void	ft_key_control2(t_gobj *game)
{
	int	moveable;

	moveable = !(game->p2->finish);
	if (game->keys_state[XK_Up] && !game->keys_state[XK_Down] && moveable)
		ft_move_plr_n(game, game->p2);
	if (game->keys_state[XK_Left] && !game->keys_state[XK_Right] && moveable)
		ft_move_plr_w(game, game->p2);
	if (game->keys_state[XK_Right] && !game->keys_state[XK_Left] && moveable)
		ft_move_plr_e(game, game->p2);
	if (game->keys_state[XK_Down] && !game->keys_state[XK_Up] && moveable)
		ft_move_plr_s(game, game->p2);
	ft_move_enemies(game);
	ft_brightness(game);
	ft_theme(game);
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
		if (game->keys_state[XK_Control_L] && game->keys_state[XK_r])
			ft_restart(game, 1);
		if (game->keys_state[XK_Control_R] && game->keys_state[XK_r])
			ft_change_screen_form(game);
		if (game->keys_state[XK_Escape])
			ft_quit_game(game);
		if (game->keys_state[XK_w] && !game->keys_state[XK_s] && moveable)
			ft_move_plr_n(game, game->p1);
		if (game->keys_state[XK_a] && !game->keys_state[XK_d] && moveable)
			ft_move_plr_w(game, game->p1);
		if (game->keys_state[XK_s] && !game->keys_state[XK_w] && moveable)
			ft_move_plr_s(game, game->p1);
		if (game->keys_state[XK_d] && !game->keys_state[XK_a] && moveable)
			ft_move_plr_e(game, game->p1);
		ft_key_control2(game);
	}
	return (0);
}
