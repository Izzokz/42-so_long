/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:21:20 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 13:21:21 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_complete(t_gobj *game)
{
	int		mp1;
	char	*msg;

	mp1 = game->p1->moves / 32;
	if (game->player_count == 0)
	{
		msg = ft_str_random(game->str.msg[1]);
		ft_printf("\n%s", msg);
		free(msg);
		ft_printf("You completed the game in %i moves !\n", mp1);
		ft_restart(game);
	}
	return (0);
}
