/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_area.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:46:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/07 17:46:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

void	ft_exit_area(t_gobj *game, t_player **player)
{
	int		pi;
	int		pj;

	pi = (*player)->i;
	pj = (*player)->j;
	if (game->map[pj][pi] == 'E' && (*player)->coin_count == 0)
		(*player)->finish = 1;
}
