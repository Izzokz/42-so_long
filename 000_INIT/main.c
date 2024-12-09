/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:49:41 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:36:45 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_set_keys(t_gobj *game)
{
	int	key_id;

	key_id = -1;
	while (++key_id < 131072)
		game->keys_state[key_id] = 0;
}

int	main(int argc, char **argv)
{
	t_gobj		game;
	t_player	p1;

	if (argc < 2)
	{
		ft_printf("No map given. Retry.");
		return (-1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_printf_err("Sorry, the game doesn't want to load", 1);
		return (-1);
	}
	game.stage = 0;
	ft_set_keys(&game);
	if (ft_init_game(&game, &p1, argv[1]) == -1)
		ft_end(&game, -1);
}
