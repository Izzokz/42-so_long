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
	t_ints		t;

	temp = ft_rlines_dup(map);
	if (!temp)
	{
		ft_printf_err("so_long:ft_flood_fill.c:31:ft_rlines_dup()", 0);
		return (0);
	}
	ft_flood_fill_p1(&temp, i, j);
	t.x = -1;
	t.count = 0;
	while (temp[++(t.x)])
	{
		t.y = -1;
		while (temp[t.x][++(t.y)])
			if (temp[t.x][t.y] != '0' && temp[t.x][t.y] != '1'
				&& temp[t.x][t.y] != '$' && temp[t.x][t.y] != '+'
				&& temp[t.x][t.y] != '-' && temp[t.x][t.y] != '@'
				&& temp[t.x][t.y] != '#' && temp[t.x][t.y] != '!'
				&& temp[t.x][t.y] != '?')
				(t.count)++;
	}
	ft_free_rlines(&temp);
	return (!t.count);
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

/*
t.count counts if it fails
*/
int	ft_playable_p2(t_rlines map, int i, int j)
{
	t_rlines	temp;
	t_ints		t;

	temp = ft_rlines_dup(map);
	if (!temp)
	{
		ft_printf_err("so_long:ft_flood_fill.c:74:ft_rlines_dup()", 0);
		return (0);
	}
	ft_flood_fill_p2(&temp, i, j);
	t.x = -1;
	t.count = 0;
	while (temp[++(t.x)])
	{
		t.y = -1;
		while (temp[t.x][++(t.y)])
			if (temp[t.x][t.y] != '0' && temp[t.x][t.y] != '1'
				&& temp[t.x][t.y] != 'C' && temp[t.x][t.y] != '+'
				&& temp[t.x][t.y] != '-' && temp[t.x][t.y] != 'P'
				&& temp[t.x][t.y] != 'E' && temp[t.x][t.y] != '!'
				&& temp[t.x][t.y] != '?')
				(t.count)++;
	}
	ft_free_rlines(&temp);
	return (!t.count);
}
