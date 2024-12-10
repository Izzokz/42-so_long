/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:42:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/10 12:42:57 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_flood_fill_p1(t_rlines *map, int i, int j)
{
	if ((*map)[i][j] == '1' || (*map)[i][j] == '+')
		return ;
	(*map)[i][j] = '1';
	ft_flood_fill_p1(map, i + 1, j);
	ft_flood_fill_p1(map, i - 1, j);
	ft_flood_fill_p1(map, i, j + 1);
	ft_flood_fill_p1(map, i, j - 1);
}

int	ft_playable_p1(t_rlines map, int i, int j)
{
	t_rlines	temp;
	int			x;
	int			y;
	int			fail;

	temp = ft_rlines_dup(map);
	if (!temp)
	{
		ft_printf_err("so_long:ft_flood_fill.c:34:ft_rlines_dup()", 0);
		return (0);
	}
	ft_flood_fill_p1(&temp, i, j);
	x = -1;
	fail = 0;
	while (temp[++x])
	{
		y = -1;
		while (temp[x][++y])
			if (temp[x][y] != '0' && temp[x][y] != '1' && temp[x][y] != '$'
				&& temp[x][y] != '+' && temp[x][y] != '-'
				&& temp[x][y] != '@' && temp[x][y] != '#')
				fail++;
	}
	ft_free_rlines(&temp);
	return (!fail);
}

static void	ft_flood_fill_p2(t_rlines *map, int i, int j)
{
	if ((*map)[i][j] == '1' || (*map)[i][j] == '+')
		return ;
	(*map)[i][j] = '1';
	ft_flood_fill_p2(map, i + 1, j);
	ft_flood_fill_p2(map, i - 1, j);
	ft_flood_fill_p2(map, i, j + 1);
	ft_flood_fill_p2(map, i, j - 1);
}

int	ft_playable_p2(t_rlines map, int i, int j)
{
	t_rlines	temp;
	int			x;
	int			y;
	int			fail;

	temp = ft_rlines_dup(map);
	if (!temp)
	{
		ft_printf_err("so_long:ft_flood_fill.c:75:ft_rlines_dup()", 0);
		return (0);
	}
	ft_flood_fill_p2(&temp, i, j);
	x = -1;
	fail = 0;
	while (temp[++x])
	{
		y = -1;
		while (temp[x][++y])
			if (temp[x][y] != '0' && temp[x][y] != '1' && temp[x][y] != 'C'
				&& temp[x][y] != '+' && temp[x][y] != '-'
				&& temp[x][y] != 'P' && temp[x][y] != 'E')
				fail++;
	}
	ft_free_rlines(&temp);
	return (!fail);
}
