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
	game->win = mlx_new_window(game->mlx, game->width * 32,
			game->height * 32, "SoulM8");
	if (!(game->win))
		return (-1);
	return (0);
}
