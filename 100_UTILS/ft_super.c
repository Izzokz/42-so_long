/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:01:18 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/13 15:01:19 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	remove_doors(t_gobj *gm)
{
	t_ints	i;

	i.i = -1;
	while (gm->str.map[++(i.i)])
	{
		i.j = -1;
		while (gm->str.map[i.i][++(i.j)])
		{
			if (gm->str.map[i.i][i.j] == '?')
			{
				gm->str.map[i.i][i.j] = '-';
				ft_update_tile(gm, i.i, i.j);
			}
			if (gm->str.map[i.i][i.j] == '!')
			{
				gm->str.map[i.i][i.j] = '0';
				ft_update_tile(gm, i.i, i.j);
			}
		}
	}
}

static int	try_remove_coin(t_gobj *gm, t_player *plr, int i, int j)
{
	if ((gm->str.map[i][j] != '$' || plr->exit != '#')
		&& (gm->str.map[i][j] != 'C' || plr->exit != 'E'))
		return (0);
	if (gm->str.map[i][j] == '$')
		plr->coin_count -= ft_collect2(gm, j * 32, i * 32);
	else
		plr->coin_count -= ft_collect(gm, j * 32, i * 32);
	ft_update_tile(gm, j, i);
	return (1);
}

static void	remove_coin(t_gobj *gm, t_player *plr, int nbr)
{
	t_ints	i;

	if (nbr == -1)
		remove_doors(gm);
	i.i = -1;
	while (gm->str.map[++(i.i)] && nbr)
	{
		i.j = -1;
		while (gm->str.map[i.i][++(i.j)] && nbr)
			nbr -= try_remove_coin(gm, plr, i.i, i.j);
	}
}

static void	super_coin(t_gobj *gm, t_player *plr)
{
	int	random_amount;

	random_amount = ft_random(100);
	if (random_amount >= 50)
		remove_coin(gm, plr, 1);
	else if (random_amount >= 15)
		remove_coin(gm, plr, 3);
	else if (random_amount > 1)
		remove_coin(gm, plr, 5);
	else
		remove_coin(gm, plr, -1);
}

void	ft_super(t_gobj *gm, t_player *plr)
{
	int	random_super;

	if (gm->str.map[plr->j / 32][plr->i / 32] != 'S')
		return ;
	gm->str.map[plr->j / 32][plr->i / 32] = '-';
	random_super = ft_random(100);
	if (random_super <= 50)
		super_coin(gm, plr);
	else if (random_super <= 98)
	{
		if (plr->spd + 1 <= 4.0f)
			plr->spd += 1;
		else
			super_coin(gm, plr);
	}
	else if (random_super == 99)
		plr->moves = 0;
	else
		remove_doors(gm);
}
