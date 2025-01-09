/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:22:38 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 13:22:40 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static void	ft_init_player(t_player *player)
{
	player->i = 0;
	player->j = 0;
	player->moves = 0;
	player->finish = 0;
}

static void	ft_init_gobj(t_gobj *game, t_player *p1)
{
	ft_init_player(p1);
	game->p1 = p1;
	game->win = NULL;
	game->imgs = NULL;
	game->dmap = NULL;
	game->map = NULL;
	game->ticks = 0;
	mlx_get_screen_size(game->mlx, &(game->win_i), &(game->win_j));
}

static void	exit_if_not_ber(t_gobj *game, const char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len <= 4 || map_name[len - 1] != 'r'
		|| map_name[len - 2] != 'e' || map_name[len - 3] != 'b'
		|| map_name[len - 4] != '.')
	{
		ft_printf("I do not think %s is a valid map name...\n", map_name);
		ft_end(game, 0);
	}
}

static int	ft_init_window(t_gobj *game)
{
	game->win = mlx_new_window(game->mlx, game->width * 32,
			game->height * 32, "so_long");
	if (!(game->win))
		return (-1);
	return (0);
}

int	ft_init_game(t_gobj *game, t_player *p1, const char *map_name)
{
	ft_init_gobj(game, p1);
	exit_if_not_ber(game, map_name);
	if (ft_init_imgs(game) == -1)
		return (-1);
	ft_map_parser(game, map_name);
	if (!game || !game->p1 || !game->imgs || !game->height || !game->width
		|| invalid_rlines(game->map) || ft_init_window(game) == -1
		|| !game->p1->coin_count)
		return (-1);
	ft_print_map(game);
	ft_printf("Moves: 0\n");
	ft_loop_process(game);
	mlx_loop(game->mlx);
	return (0);
}
