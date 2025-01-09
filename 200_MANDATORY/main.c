/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:15:30 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 13:15:32 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static void	ft_set_keys(t_gobj *game)
{
	int	i;

	i = -1;
	while (++i < 131072)
		game->keys_state[i] = 0;
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
	ft_set_keys(&game);
	if (ft_init_game(&game, &p1, argv[1]) == -1)
		ft_end(&game, -1);
}
