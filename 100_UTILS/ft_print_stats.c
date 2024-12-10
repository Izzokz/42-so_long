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

static int	center_stats(char *stats, int i)
{
	return ((i + 8) - (ft_strlen(stats) * 6 / 2));
}

void	ft_print_stats(t_gobj *game)
{
	int	mp1;
	int	mp2;
	int	cp1;
	int	cp2;
	int	players;

	players = game->player_count;
	mp1 = game->p1->moves / 32;
	cp1 = game->p1->coin_count;
	if (game->p1->finish == 0)
		mlx_string_put(game->mlx, game->win, center_stats("ABCDEABCDEAAABCDE", game->p1->i),
				game->p1->j - 4, 0x000000, "ABCDEABCDEAAABCDE");
	ft_printf("%sPlayers : %d", OWLINE, players);
	ft_printf("P1 Moves: %d\t", mp1);
	ft_printf("P1 Remaining Coins: %d", cp1);
	if (game->p2->finish == 0)
	{
		mp2 = game->p2->moves / 32;
		cp2 = game->p2->coin_count;
		ft_printf("\rPlayers : %d\t", players);
		ft_printf("P2 Moves: %d\t", mp2);
		ft_printf("P2 Remaining Coins: %d", cp2);
	}
}
