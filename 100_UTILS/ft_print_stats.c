/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:17:19 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 13:17:20 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_stats(t_gobj *game)
{
	int	mp1;
	int	cp1;
	int	players;

	players = game->player_count;
	mp1 = game->p1->moves / 32;
	cp1 = game->p1->coin_count;
	ft_printf("\rPlayers : %d\t", players);
	ft_printf("P1 Moves: %d\t", mp1);
	ft_printf("P1 Remaining Coins: %d", cp1);
}
