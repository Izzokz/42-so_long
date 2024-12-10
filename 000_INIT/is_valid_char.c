/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:57:59 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/10 09:58:01 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
i.count counts the number of player2
i.count1 counts the number of exit2
i.count2 counts the number of coin2

Returns 'a' if there's no second player without a proper environment
Returns 'b' if there's no second player with a playable environment
Returns 'c' if there's a second player without a proper environment
Returns 'd' if there's a second player with a playable environment
Returns 'e' there's too much player2
*/
char	ft_two_players_manager(t_rlines map)
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
			if (map[i.i][i.j] == '@')
				i.count += 1;
			if (map[i.i][i.j] == '#')
				i.count1 += 1;
			if (map[i.i][i.j] == '$')
				i.count2 += 1;
		}
	}
	if (i.count == 0)
		return ('a' + i.count2 == 0 && (i.count1 == 1 || i.count1 == 0));
	if (i.count == 1)
		return ('c' + i.count1 == 1 && i.count2 > 0);
	return ('e');
}

int	is_rect_map(t_rlines map)
{
	t_ints	i;

	i.i = -1;
	i.len = -1;
	while (map[++(i.i)])
	{
		if (i.len == -1)
			i.len = ft_strlen(map[i.i]);
		if ((size_t)i.len != ft_strlen(map[i.i]))
			return (0);
	}
	return (1);
}

int	are_valid_walls(t_rlines map)
{
	t_ints	i;

	i.len = ft_strlen(map[0]);
	i.len1 = ft_rlines_len(map);
	i.i = -1;
	while (++(i.i) < i.len)
		if ((map[i.len1 - 1][i.i] != '1' && map[i.len1 - 1][i.i] != '+')
			|| (map[0][i.i] != '1' && map[0][i.i] != '+'))
			return (0);
	i.i = 0;
	while (++(i.i) < i.len1 - 1)
		if ((map[i.i][i.len - 1] != '1' && map[i.i][i.len - 1] != '+')
			|| (map[i.i][0] != '1' && map[i.i][0] != '+'))
			return (0);
	return (1);
}

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == '-'
		|| c == 'E' || c == 'C' || c == '+' || c == '$'
		|| c == '#' || c == '@');
}
