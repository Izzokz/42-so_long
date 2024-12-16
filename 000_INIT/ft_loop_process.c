/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:18:06 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/05 14:18:07 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	key_enable(int keycode, t_gobj *game)
{
	if (keycode >= 0 && keycode < 131072)
		game->keys_state[keycode] = 1;
	return (0);
}

static int	key_disable(int keycode, t_gobj *game)
{
	if (keycode >= 0 && keycode < 131072)
		game->keys_state[keycode] = 0;
	return (0);
}

static int	all_processes(t_gobj *game)
{
	if (game->loaded)
	{
		ft_unlock_player(game, game->p1);
		ft_unlock_player(game, game->p2);
		ft_move_enemies(game);
		ft_key_control(game);
		is_complete(game);
	}
	return (0);
}

static int	what_the(t_gobj *game)
{
	ft_printf("%sSurprising choice...\n", OWLINE);
	ft_end(game, 0);
	return (0);
}

int	ft_loop_process(t_gobj *game)
{
	mlx_hook(game->win, 25, 1L << 18, ft_updated_window_re_print, game);
	mlx_hook(game->win, 17, 0, what_the, game);
	mlx_hook(game->win, 2, 1L << 0, key_enable, game);
	mlx_hook(game->win, 3, 1L << 1, key_disable, game);
	mlx_loop_hook(game->mlx, all_processes, game);
	return (0);
}
