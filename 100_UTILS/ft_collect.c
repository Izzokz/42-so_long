/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:10:05 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 11:10:07 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_collect_super(t_gobj *game, int pi, int pj)
{
	if (game->str.map[pj / 32][pi / 32] == 'S')
	{
		game->str.map[pj / 32][pi / 32] = '-';
		return (1);
	}
	if (game->str.map[(pj + 15) / 32][pi / 32] == 'S')
	{
		game->str.map[(pj + 15) / 32][pi / 32] = '-';
		return (1);
	}
	if (game->str.map[pj / 32][(pi + 15) / 32] == 'S')
	{
		game->str.map[pj / 32][(pi + 15) / 32] = '-';
		return (1);
	}
	if (game->str.map[(pj + 15) / 32][(pi + 15) / 32] == 'S')
	{
		game->str.map[(pj + 15) / 32][(pi + 15) / 32] = '-';
		return (1);
	}
	return (0);
}

int	ft_collect2(t_gobj *game, int pi, int pj)
{
	if (game->str.map[pj / 32][pi / 32] == '$')
	{
		game->str.map[pj / 32][pi / 32] = '-';
		return (1);
	}
	if (game->str.map[(pj + 15) / 32][pi / 32] == '$')
	{
		game->str.map[(pj + 15) / 32][pi / 32] = '-';
		return (1);
	}
	if (game->str.map[pj / 32][(pi + 15) / 32] == '$')
	{
		game->str.map[pj / 32][(pi + 15) / 32] = '-';
		return (1);
	}
	if (game->str.map[(pj + 15) / 32][(pi + 15) / 32] == '$')
	{
		game->str.map[(pj + 15) / 32][(pi + 15) / 32] = '-';
		return (1);
	}
	return (0);
}

int	ft_collect(t_gobj *game, int pi, int pj)
{
	if (game->str.map[pj / 32][pi / 32] == 'C')
	{
		game->str.map[pj / 32][pi / 32] = '0';
		return (1);
	}
	if (game->str.map[(pj + 15) / 32][pi / 32] == 'C')
	{
		game->str.map[(pj + 15) / 32][pi / 32] = '0';
		return (1);
	}
	if (game->str.map[pj / 32][(pi + 15) / 32] == 'C')
	{
		game->str.map[pj / 32][(pi + 15) / 32] = '0';
		return (1);
	}
	if (game->str.map[(pj + 15) / 32][(pi + 15) / 32] == 'C')
	{
		game->str.map[(pj + 15) / 32][(pi + 15) / 32] = '0';
		return (1);
	}
	return (0);
}
