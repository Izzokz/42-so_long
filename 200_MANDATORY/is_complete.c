/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:45:06 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 14:45:07 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

int	is_complete(t_gobj *game)
{
	if (!game->p1->finish)
		return (0);
	ft_printf("You completed the game in %i moves !\n", game->p1->moves);
	ft_end(game, 0);
	return (1);
}
