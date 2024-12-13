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

static int	ft_start_flood_fill(t_rlines map, int i, int j)
{
	if (map[i][j] == '@')
		return (ft_playable_p2(map, i, j));
	if (map[i][j] == 'P')
		return (ft_playable_p1(map, i, j));
	return (1);
}

/*
i.count counts the number of player1
i.count1 counts the number of exit1
i.count2 counts the number of coin1
*/
static int	is_doable(t_rlines map)
{
	t_ints	i;
	char	two_players;

	two_players = ft_two_players_manager(map);
	if (two_players == 'a' || two_players == 'c' || two_players == 'e')
		return (0);
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

static int	valid_door_placement(t_gobj *game)
{
	t_ints	i;

	i.i = -1;
	while (game->str.map[++(i.i)])
	{
		i.j = -1;
		while (game->str.map[i.i][++(i.j)])
			if ((game->str.map[i.i][i.j] == '?'
				&& ((game->str.map[i.i + 1][i.j] == '?'
					&& game->str.map[i.i - 1][i.j] == '?')
				|| (game->str.map[i.i][i.j + 1] == '?'
				&& game->str.map[i.i][i.j - 1] == '?')))
				|| (game->str.map[i.i][i.j] == '!'
				&& ((game->str.map[i.i + 1][i.j] == '!'
				&& game->str.map[i.i - 1][i.j] == '!')
				|| (game->str.map[i.i][i.j + 1] == '!'
				&& game->str.map[i.i][i.j - 1] == '!'))))
				return (0);
	}
	return (1);
}

static int	valid_map(t_gobj *game)
{
	t_ints	ints;

	ints.i = -1;
	game->height = ft_rlines_len(game->str.map);
	game->width = ft_strlen(game->str.map[0]);
	if (game->width > 42 || game->height > 42)
	{
		ft_printf("Your map can't be bigger than 42 * 42.\n");
		return (0);
	}
	if (!is_rect_map(game->str.map) || !are_valid_walls(game->str.map))
		return (0);
	while (game->str.map[++(ints.i)])
	{
		ints.j = -1;
		while (game->str.map[ints.i][++(ints.j)])
		{
			if (!is_valid_char(game->str.map[ints.i][ints.j]))
				return (0);
			if (game->str.map[ints.i][ints.j] == '@')
				game->p2->finish = 0;
		}
	}
	return (is_doable(game->str.map) && valid_door_placement(game));
}

void	ft_map_parser(t_gobj *game, char *map_name)
{
	ft_get_map_data(game, map_name);
	if (invalid_rlines(game->str.map) || invalid_slines(game->str.msg)
		|| zombie_rlines_free(&(game->str.map_dep)))
	{
		ft_printf("Something did not work, double check your map's file.\n");
		ft_end(game, -1);
	}
	ft_rlines_cutendl(&(game->str.map));
	if (invalid_rlines(game->str.map) || !valid_map(game))
	{
		ft_printf("%s can't be done. Double check it.\n", map_name);
		ft_end(game, -1);
	}
	ft_set_players(game);
	game->height = ft_rlines_len(game->str.map);
	game->width = ft_strlen(game->str.map[0]);
	game->p1->coin_count = ft_count_coins(game, 'C');
	if (game->p2->finish == 0)
		game->p2->coin_count = ft_count_coins(game, '$');
}
