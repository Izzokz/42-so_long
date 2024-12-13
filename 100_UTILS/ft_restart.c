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

void	ft_restart(t_gobj *game, int retry)
{
	if (!(game->str.map_dep) && !retry)
		ft_end(game, 0);
	if (!retry)
	{
		game->stage += 1;
		game->str.next_map = ft_str_random(game->str.map_dep);
	}
	else
	{
		game->retry += 1;
		game->str.next_map = ft_strdup(game->current_map);
		ft_printf("Stucked ???\n");
	}
	if (!game->str.next_map)
	{
		ft_printf_err("Sorry, we encountered issue generating another map", 1);
		ft_end(game, -1);
	}
	if (ft_init_game(game, game->p1, game->p2, game->str.next_map) == -1)
		ft_end(game, -1);
}
