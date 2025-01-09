/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:33:09 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 14:33:10 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

int	ft_get_map_data(t_gobj *game, const char *map_name)
{
	game->map = ft_readfile(map_name);
	if (invalid_rlines_free(&(game->map)))
	{
		ft_printf_err("Corrupted map_data", 1);
		return (-1);
	}
	return (0);
}
