/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_doors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:15:30 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/11 16:15:31 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_print_odd_door(t_gobj *game, int i, int j)
{
	if ((game->p1->coin_count + game->p2->coin_count + game->keys) % 2)
		ft_copy_to_dmap(game, game->imgs[6], j * 32, i * 32);
	else
		ft_copy_to_dmap(game, game->imgs[11], j * 32, i * 32);
}

static void	ft_print_even_door(t_gobj *game, int i, int j)
{
	if ((game->p1->coin_count + game->p2->coin_count + game->keys) % 2 == 0)
		ft_copy_to_dmap(game, game->imgs[0], j * 32, i * 32);
	else
		ft_copy_to_dmap(game, game->imgs[10], j * 32, i * 32);
}

void	ft_print_doors(t_gobj *game)
{
	t_ints	i;

	i.i = -1;
	while (game->str.map[++(i.i)])
	{
		i.j = -1;
		while (game->str.map[i.i][++(i.j)])
		{
			if (game->str.map[i.i][i.j] == '!')
				ft_print_even_door(game, i.i, i.j);
			if (game->str.map[i.i][i.j] == '?')
				ft_print_odd_door(game, i.i, i.j);
		}
	}
}
