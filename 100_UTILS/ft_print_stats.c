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

static int	center_stat(char *stat, int i)
{
	return ((i + 8) - (ft_strlen(stat) * 6 / 2));
}

static void	refresh_stat(char **stat)
{
	if (*stat)
	{
		free(*stat);
		stat = NULL;
	}
}

static char	**get_stat(t_gobj *game, int i)
{
	static char	*mp1 = NULL;
	static char	*mp2 = NULL;
	static char	*cp3 = NULL;

	if (i == 1)
	{
		mp1 = ft_itoa(game->p1->moves / 32);
		return (&mp1);
	}
	if (i == 2)
	{
		mp2 = ft_itoa(game->p2->moves / 32);
		return (&mp2);
	}
	if (game->p3->t_i == 0 && game->p3->t_j == 0
		&& game->p3->ticks < 750)
		cp3 = ft_itoa(750 - game->p3->ticks);
	else if ((game->p3->t_i != 0 || game->p3->t_j != 0)
		&& game->p3->ticks < 30)
		cp3 = ft_itoa(30 - game->p3->ticks);
	else
		cp3 = ft_strdup("ACTIVE");
	return (&cp3);
}

static void	ft_print_stats_p2(t_gobj *game, char **stat)
{
	stat = get_stat(game, 2);
	mlx_string_put(game->mlx, game->win,
		center_stat(*stat, game->p2->i + (game->win_i - game->width * 32) / 2),
		game->p2->j - 4, 0x408A00, *stat);
	refresh_stat(stat);
}

void	ft_print_stats(t_gobj *game)
{
	char	**stat;

	if (!game->p1->finish)
	{
		stat = get_stat(game, 1);
		mlx_string_put(game->mlx, game->win,
			center_stat(*stat, game->p1->i
				+ (game->win_i - game->width * 32) / 2),
			game->p1->j - 4, 0x408A00, *stat);
		refresh_stat(stat);
	}
	if (game->p3)
	{
		stat = get_stat(game, 3);
		mlx_string_put(game->mlx, game->win,
			center_stat(*stat, game->p3->i
				+ (game->win_i - game->width * 32) / 2),
			game->p3->j - 4, 0xCC0000, *stat);
		refresh_stat(stat);
	}
	if (!game->p2->finish)
		ft_print_stats_p2(game, stat);
}
