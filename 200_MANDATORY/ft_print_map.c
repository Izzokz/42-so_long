/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:42:54 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/07 15:42:55 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static void	ft_call_copy(t_gobj *game, int i, int j)
{
	if (game->p1->i == j && game->p1->j == i)
		mlx_put_image_to_window(game->mlx,
			game->win, game->imgs[2], j * 32, i * 32);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->imgs[0], j * 32, i * 32);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->imgs[1], j * 32, i * 32);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->imgs[3], j * 32, i * 32);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->imgs[4], j * 32, i * 32);
}

void	ft_print_map(t_gobj *game)
{
	t_ints	i;

	i.i = -1;
	while (game->map[++(i.i)])
	{
		i.j = -1;
		while (game->map[i.i][++(i.j)])
			ft_call_copy(game, i.i, i.j);
	}
}

void	ft_update_dmap(t_gobj *game, int i, int j)
{
	ft_call_copy(game, j, i);
	ft_call_copy(game, game->p1->j, game->p1->i);
}
