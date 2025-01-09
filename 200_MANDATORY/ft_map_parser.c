/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:44:50 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 13:44:52 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static void	ft_flood_fill(t_rlines *map, int i, int j)
{
	if ((*map)[i][j] == '1')
		return ;
	(*map)[i][j] = '1';
	ft_flood_fill(map, i + 1, j);
	ft_flood_fill(map, i - 1, j);
	ft_flood_fill(map, i, j + 1);
	ft_flood_fill(map, i, j - 1);
}

static int	ft_start_flood_fill(t_rlines map, int i, int j)
{
	t_rlines	temp;
	t_ints		t;

	if (map[i][j] != 'P')
		return (1);
	temp = ft_rlines_dup(map);
	if (!temp)
	{
		ft_printf_err("so_long:ft_map_parser.c:33:ft_rlines_dup()", 0);
		return (0);
	}
	ft_flood_fill(&temp, i, j);
	t.x = -1;
	t.count = 0;
	while (temp[++(t.x)])
	{
		t.y = -1;
		while (temp[t.x][++(t.y)])
			if (temp[t.x][t.y] != '0' && temp[t.x][t.y] != '1')
				(t.count)++;
	}
	ft_free_rlines(&temp);
	return (!t.count);
}

static int	is_doable(t_rlines map)
{
	t_ints	i;

	i.count = 0;
	i.count1 = 0;
	i.count2 = 0;
	i.i = -1;
	while (map[++(i.i)])
	{
		i.j = -1;
		while (map[i.i][++(i.j)])
		{
			i.count += map[i.i][i.j] == 'P';
			i.count1 += map[i.i][i.j] == 'E';
			i.count2 += map[i.i][i.j] == 'C';
			if (i.count > 1 || i.count1 > 1
				|| !ft_start_flood_fill(map, i.i, i.j))
				return (0);
		}
	}
	return (i.count2 > 0);
}

static int	valid_map(t_gobj *game)
{
	t_ints	ints;

	ints.i = -1;
	game->height = ft_rlines_len(game->map);
	game->width = ft_strlen(game->map[0]);
	if (game->width * 32 > game->win_i || game->height * 32 > game->win_j - 64)
		return (ft_printf("Your map can't be bigger than your screen\n") * 0);
	if (game->width > 42 || game->height > 42)
		return (ft_printf("Your map can't be bigger than 42 * 42.\n") * 0);
	if (!is_rect_map(game->map) || !are_valid_walls(game->map))
		return (0);
	while (game->map[++(ints.i)])
	{
		ints.j = -1;
		while (game->map[ints.i][++(ints.j)])
			if (!is_valid_char(game->map[ints.i][ints.j]))
				return (0);
	}
	return (is_doable(game->map));
}

void	ft_map_parser(t_gobj *game, const char *map_name)
{
	ft_get_map_data(game, map_name);
	if (invalid_rlines(game->map))
	{
		ft_printf("Something did not work, double check your map's file.\n");
		ft_end(game, -1);
	}
	ft_rlines_cutendl(&(game->map));
	if (invalid_rlines(game->map) || !valid_map(game))
	{
		ft_printf("%s can't be done. Double check it.\n", map_name);
		ft_end(game, -1);
	}
	ft_set_player(game);
	game->p1->coin_count = ft_count_coins(game);
}
