/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:02:30 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 22:02:31 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_restart(t_gobj *game)
{
	game->stage += 1;
	if (!(game->str.map_dep))
		ft_end(game, 0);
	game->str.next_map = ft_str_random(game->str.map_dep);
	if (!game->str.next_map)
	{
		ft_printf_err("Sorry, we encountered issue generating another map", 1);
		ft_end(game, -1);
	}
	if (ft_init_game(game, game->p1, game->str.next_map) == -1)
		ft_end(game, -1);
}
