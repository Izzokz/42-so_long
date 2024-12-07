/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:58:22 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:42:43 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(t_rlines *map, int i, int j)
{
	if ((*map)[i][j] == '1')
		return ;
	(*map)[i][j] = '1';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}

static int	flood_fill_complete(t_rlines map, int i, int j)
{
	t_rlines	temp;
	int			x;
	int			y;
	int			fail;

	temp = ft_rlines_dup(map);
	if (!temp)
	{
		ft_printf_err("so_long:ft_map_parser.c:37:ft_rlines_dup()", 0);
		return (0);
	}
	flood_fill(&temp, i, j);
	x = -1;
	fail = 0;
	while (temp[++x])
	{
		y = -1;
		while (temp[x][++y])
			if (temp[x][y] != '0' && temp[x][y] != '1')
				fail++;
	}
	ft_free_rlines(&temp);
	return (!fail);
}

static int	is_doable(t_rlines map)
{
	int	p_count;
	int	e_count;
	int	i;
	int	j;

	i = -1;
	p_count = 0;
	e_count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				p_count += 1;
				if (!flood_fill_complete(map, i, j) || p_count > 1)
					return (0);
			}
			if (map[i][j] == 'E')
				e_count += 1;
		}
	}
	return (p_count == 1 && e_count == 1);
}

static int	valid_map(t_rlines map)
{
	t_ints	ints;

	ints.i = -1;
	ints.len = 0;
	ints.x = ft_rlines_len(map);
	ints.y = ft_strlen(map[0]);
	while (map[++(ints.i)])
	{
		ints.j = -1;
		while (map[ints.i][++(ints.j)])
		{
			if ((map[ints.i][ints.j] != '0' && map[ints.i][ints.j] != '1'
				&& map[ints.i][ints.j] != 'C' && map[ints.i][ints.j] != 'P'
				&& map[ints.i][ints.j] != 'E')
				|| ((ints.i == 0 || ints.j == 0
				|| ints.i == ints.x - 1 || ints.j == ints.y - 1)
				&& map[ints.i][ints.j] != '1'))
				return (0);
		}
		if (ints.len == 0)
			ints.len = ints.j;
		if (ints.j == 0 || ints.j != ints.len)
			return (0);
	}
	return (is_doable(map));
}

void	ft_map_parser(t_gobj *game, char *map_name)
{
	if (ft_set_str(game) == -1)
		ft_end(game, -1);
	ft_get_map_data(game, map_name);
	if (invalid_rlines(game->str.map) || invalid_slines(game->str.msg)
		|| zombie_rlines_free(&(game->str.map_dep)))
	{
		ft_printf("Something did not work. Sorry for the disappointment.\n");
		ft_end(game, -1);
	}
	ft_rlines_cutendl(&(game->str.map));
	if (invalid_rlines(game->str.map) || !valid_map(game->str.map))
	{
		ft_printf("%s can't be done. Doucle check it.\n", map_name);
		ft_end(game, -1);
	}
	ft_set_player(game);
	game->height = ft_rlines_len(game->str.map);
	game->width = ft_strlen(game->str.map[0]);
	game->p1->coin_count = ft_count_coins(game, 'C');
}
