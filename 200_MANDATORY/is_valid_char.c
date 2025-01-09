/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:50:56 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 13:50:57 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

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
		if (map[i.len1 - 1][i.i] != '1' || map[0][i.i] != '1')
			return (0);
	i.i = 0;
	while (++(i.i) < i.len1 - 1)
		if (map[i.i][i.len - 1] != '1' || map[i.i][0] != '1')
			return (0);
	return (1);
}

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C');
}
