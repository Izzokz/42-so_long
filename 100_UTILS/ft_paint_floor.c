/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:20:11 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/16 17:20:13 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_paint_floor(t_gobj *g, t_player *p)
{
	if (!g->paint)
		return ;
	if (g->str.map[p->j / 32][p->i / 32] == '0' && p->exit == '#')
		g->str.map[p->j / 32][p->i / 32] = '-';
	if (g->str.map[(p->j + 15) / 32][p->i / 32] == '0' && p->exit == '#')
		g->str.map[(p->j + 15) / 32][p->i / 32] = '-';
	if (g->str.map[p->j / 32][(p->i + 15) / 32] == '0' && p->exit == '#')
		g->str.map[p->j / 32][(p->i + 15) / 32] = '-';
	if (g->str.map[(p->j + 15) / 32][(p->i + 15) / 32] == '0' && p->exit == '#')
		g->str.map[(p->j + 15) / 32][(p->i + 15) / 32] = '-';
	if (g->str.map[p->j / 32][p->i / 32] == '-' && p->exit == 'E')
		g->str.map[p->j / 32][p->i / 32] = '0';
	if (g->str.map[(p->j + 15) / 32][p->i / 32] == '-' && p->exit == 'E')
		g->str.map[(p->j + 15) / 32][p->i / 32] = '0';
	if (g->str.map[p->j / 32][(p->i + 15) / 32] == '-' && p->exit == 'E')
		g->str.map[p->j / 32][(p->i + 15) / 32] = '0';
	if (g->str.map[(p->j + 15) / 32][(p->i + 15) / 32] == '-' && p->exit == 'E')
		g->str.map[(p->j + 15) / 32][(p->i + 15) / 32] = '0';
}
