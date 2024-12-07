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
	ft_key_control(game);
	is_complete(game);
	return (0);
}

int	ft_loop_process(t_gobj *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_enable, game);
	mlx_hook(game->win, 3, 1L << 1, key_disable, game);
	mlx_loop_hook(game->mlx, all_processes, game);
	return (0);
}
