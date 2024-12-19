/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ene_stats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:34:59 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/18 11:35:00 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_ene_stats(t_enemy *ene, char type, int i, int j)
{
	ene->type = type;
	ene->i = j * 32 + 8;
	ene->j = i * 32 + 8;
	if (type == 'M')
		ene->spd = 2;
	else
		ene->spd = 1;
	ene->q_pass = 0;
	ene->ticks = 0;
	ene->t_i = 0;
	ene->t_j = 0;
}
