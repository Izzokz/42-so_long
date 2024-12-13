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
	int		tot_mp;
	char	*msg;

	if (game->p1->finish == 1 && (game->p2->finish == -2
			|| game->p2->finish == 1))
	{
		tot_mp = (game->p1->moves / 32) + (game->p2->moves / 32);
		msg = ft_str_random(game->str.msg[1]);
		ft_printf("%s%s\n", OWLINE, msg);
		free(msg);
		ft_printf("You completed the game in %i moves !\n", tot_mp);
		ft_restart(game, 0);
	}
	return (0);
}
