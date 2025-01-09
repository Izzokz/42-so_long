/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:48:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 14:48:59 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

void	ft_end(t_gobj *game, int exit_id)
{
	int		i;

	if (!game)
		exit(-1);
	i = -1;
	ft_free_rlines(&(game->map));
	while (game->imgs && game->imgs[++i])
		mlx_destroy_image(game->mlx, game->imgs[i]);
	free(game->imgs);
	if (game->dmap)
		mlx_destroy_image(game->mlx, game->dmap);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(exit_id);
}
