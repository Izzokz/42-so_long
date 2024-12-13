/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:25:57 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/09 14:25:58 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_init_window(t_gobj *game)
{
	if (game->stage > 0 || game->retry > 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->screen_form, 0, 0);
		return (0);
	}
	ft_screen_form(game);
	game->win = mlx_new_window(game->mlx, game->win_i, game->win_j, "SoulM8");
	if (!(game->win))
		return (-1);
	ft_screen_form(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen_form, 0, 0);
	return (0);
}
