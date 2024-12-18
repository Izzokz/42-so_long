/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_teleport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:47:04 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/18 10:47:05 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

static void	ft_swap(t_gobj *game, t_enemy *ene)
{
	t_enemy	*random_ene;
	int		tmp_i;
	int		tmp_j;
	int		i;

	i = 7;
	while (--i)
	{
		random_ene = (t_enemy *)ft_ptr_random((void **)game->enemies);
		if (is_lowercase(random_ene->type)
			&& is_valid_move(game, random_ene->i, random_ene->j))
		{
			tmp_i = random_ene->i;
			tmp_j = random_ene->j;
			random_ene->i = ene->i;
			random_ene->j = ene->j;
			ene->i = tmp_i;
			ene->j = tmp_j;
			break ;
		}
	}
}

static int	ft_set_pos(t_gobj *game, t_enemy *ene, int i, int j)
{
	int	id;
	int	prev_i;
	int	prev_j;

	if (i <= 0 || i >= game->width || j <= 0 || j >= game->height)
		return (0);
	if (!is_valid_move(game, i * 32, j * 32))
		return (0);
	id = -1;
	while (game->enemies[++id])
	{
		if (game->enemies[id]->i / 32 == i
			&& game->enemies[id]->j / 32 == j
			&& (game->enemies[id]->type == 'h'
				|| game->enemies[id]->type == 'H'))
			return (0);
	}
	prev_i = ene->i;
	prev_j = ene->j;
	ene->i = i * 32;
	ene->j = j * 32;
	ft_update_dmap(game, prev_i, prev_j);
	return (1);
}

void	ft_teleport(t_gobj *game, t_enemy *ene, t_player *plr)
{
	if (ene->type == 'h')
		return (ft_swap(game, ene));
	if (ft_set_pos(game, ene, plr->i / 32, plr->j / 32 - 3))
		return ;
	if (ft_set_pos(game, ene, plr->i / 32, plr->j / 32 + 3))
		return ;
	if (ft_set_pos(game, ene, plr->i / 32 - 3, plr->j / 32))
		return ;
	if (ft_set_pos(game, ene, plr->i / 32 + 3, plr->j / 32))
		return ;
	if (ft_set_pos(game, ene, plr->i / 32 - 3, plr->j / 32 - 3))
		return ;
	if (ft_set_pos(game, ene, plr->i / 32 + 3, plr->j / 32 - 3))
		return ;
	if (ft_set_pos(game, ene, plr->i / 32 - 3, plr->j / 32 + 3))
		return ;
	if (ft_set_pos(game, ene, plr->i / 32 + 3, plr->j / 32 + 3))
		return ;
}
