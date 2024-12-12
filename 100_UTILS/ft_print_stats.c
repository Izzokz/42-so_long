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
	static char	*cp1 = NULL;
	static char	*mp1 = NULL;
	static char	*cp2 = NULL;
	static char	*mp2 = NULL;

	if (i == 0)
	{
		cp1 = ft_itoa(game->p1->coin_count);
		return (&cp1);
	}
	if (i == 1)
	{
		mp1 = ft_itoa(game->p1->moves / 32);
		return (&mp1);
	}
	if (i == 2)
	{
		cp2 = ft_itoa(game->p2->coin_count);
		return (&cp2);
	}
	mp2 = ft_itoa(game->p2->moves / 32);
	return (&mp2);
}

void	ft_print_stats(t_gobj *game)
{
	char	**stat;

	if (game->p1->finish == 0)
	{
		stat = get_stat(game, 1);
		mlx_string_put(game->mlx, game->win, center_stat(*stat, game->p1->i),
			game->p1->j - 4, 0x408A00, *stat);
		refresh_stat(stat);
	}
	if (game->p2->finish != 0)
		return ;
	stat = get_stat(game, 3);
	mlx_string_put(game->mlx, game->win, center_stat(*stat, game->p2->i),
		game->p2->j - 4, 0x408A00, *stat);
	refresh_stat(stat);
}
