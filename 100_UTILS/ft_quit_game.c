/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:29:25 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 15:29:29 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_quit_game(t_gobj *game)
{
	char	*msg;

	msg = ft_str_random(game->str.msg[0]);
	ft_printf("\n%s\n", msg);
	free(msg);
	ft_end(game, 0);
}
