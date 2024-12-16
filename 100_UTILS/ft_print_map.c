/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:11:32 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:49:23 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_gen_dmap(t_gobj *game)
{
	if (!game->dmap)
		game->dmap = mlx_new_image(game->mlx, game->width * 32,
				game->height * 32);
	if (!game->dmap)
	{
		ft_printf_err("A problem occured: ft_print_map.c: 47", 1);
		ft_end(game, -1);
	}
}

static void	ft_call_copy(t_gobj *game, int i, int j)
{
	if (game->str.map[i][j] == '0' || game->str.map[i][j] == 'C'
		|| game->str.map[i][j] == 'K')
		ft_copy_to_dmap(game, game->imgs[0], j * 32, i * 32);
	if (game->str.map[i][j] == '1')
		ft_copy_to_dmap(game, game->imgs[1], j * 32, i * 32);
	if (game->str.map[i][j] == 'C')
		ft_copy_to_dmap(game, game->imgs[3], j * 32 + 8, i * 32 + 8);
	if (game->str.map[i][j] == 'E')
		ft_copy_to_dmap(game, game->imgs[4], j * 32, i * 32);
	if (game->str.map[i][j] == '+')
		ft_copy_to_dmap(game, game->imgs[5], j * 32, i * 32);
	if (game->str.map[i][j] == '-' || game->str.map[i][j] == '$'
		|| game->str.map[i][j] == 'S')
		ft_copy_to_dmap(game, game->imgs[6], j * 32, i * 32);
	if (game->str.map[i][j] == '#')
		ft_copy_to_dmap(game, game->imgs[8], j * 32, i * 32);
	if (game->str.map[i][j] == '$')
		ft_copy_to_dmap(game, game->imgs[9], j * 32 + 8, i * 32 + 8);
	if (game->str.map[i][j] == 'S')
		ft_copy_to_dmap(game, game->imgs[12], j * 32 + 8, i * 32 + 8);
	if (game->str.map[i][j] == 'K')
		ft_copy_to_dmap(game, game->imgs[13], j * 32 + 8, i * 32 + 8);
}

void	ft_print_map(t_gobj *game)
{
	t_ints	i;

	ft_gen_dmap(game);
	i.i = -1;
	while (game->str.map[++(i.i)])
	{
		i.j = -1;
		while (game->str.map[i.i][++(i.j)])
			ft_call_copy(game, i.i, i.j);
	}
	ft_print_doors(game);
	ft_print_entities(game);
	mlx_put_image_to_window(game->mlx, game->win, game->dmap,
		(game->win_i - game->width * 32) / 2, 0);
}

void	ft_update_tile(t_gobj *game, int i, int j)
{
	ft_call_copy(game, i, j);
	ft_print_doors(game);
	ft_print_entities(game);
	mlx_put_image_to_window(game->mlx, game->win, game->dmap,
		(game->win_i - game->width * 32) / 2, 0);
}

/*
Updates 3x3 tiles from one position
*/
void	ft_update_dmap(t_gobj *game, int i, int j)
{
	ft_call_copy(game, j / 32, i / 32);
	ft_call_copy(game, (j / 32) + 1, i / 32);
	ft_call_copy(game, j / 32, (i / 32) + 1);
	ft_call_copy(game, (j / 32) + 1, (i / 32) + 1);
	ft_call_copy(game, (j / 32) - 1, i / 32);
	ft_call_copy(game, j / 32, (i / 32) - 1);
	ft_call_copy(game, (j / 32) - 1, (i / 32) - 1);
	ft_call_copy(game, (j / 32) + 1, (i / 32) - 1);
	ft_call_copy(game, (j / 32) - 1, (i / 32) + 1);
	ft_print_doors(game);
	ft_print_entities(game);
	mlx_put_image_to_window(game->mlx, game->win, game->dmap,
		(game->win_i - game->width * 32) / 2, 0);
}
