/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:32:54 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/17 19:32:56 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_clone_enemies(t_enemy ***from, t_enemy ***to, int id)
{
	t_ints	i;

	i.i = -1;
	i.j = -1;
	while (*from && (*from)[++(i.i)])
	{
		if (i.i != id)
		{
			(*to)[++(i.j)] = ft_calloc(1, sizeof(t_enemy));
			if (!(*to)[i.j])
			{
				ft_free_enemies(to);
				ft_free_enemies(from);
				return (-1);
			}
			((*to)[i.j])->i = ((*from)[i.i])->i;
			((*to)[i.j])->j = ((*from)[i.i])->j;
			((*to)[i.j])->spd = ((*from)[i.i])->spd;
			((*to)[i.j])->type = ((*from)[i.i])->type;
			((*to)[i.j])->active = ((*from)[i.i])->active;
			((*to)[i.j])->t_i = ((*from)[i.i])->t_i;
			((*to)[i.j])->t_j = ((*from)[i.i])->t_j;
		}
	}
	return (0);
}

static int	ft_dealloc_enemies(t_gobj *game, int id)
{
	t_enemy	**tmp;
	int		len;

	len = 0;
	while (game->enemies && game->enemies[len])
		len++;
	tmp = ft_calloc(len, sizeof(t_enemy *));
	if (!tmp)
		return (-1);
	if (ft_clone_enemies(&(game->enemies), &tmp, id) == -1)
		return (-1);
	len = 0;
	while (tmp[len])
		len++;
	ft_free_enemies(&(game->enemies));
	game->enemies = ft_calloc(len + 1, sizeof(t_enemy *));
	if (ft_clone_enemies(&tmp, &(game->enemies), -1) == -1)
		return (-1);
	ft_free_enemies(&tmp);
	return (0);
}

int	ft_merge_from(t_gobj *game, t_enemy *ene, int id)
{
	int	i;

	i = -1;
	if (ene->type == 'q' || ene->type == 'B' || ene->type == 'b')
		return (0);
	while (game->enemies[++i])
	{
		if (i != id && game->enemies[i]->type != 'q'
			&& game->enemies[i]->type != 'B'
			&& game->enemies[i]->type != 'b'
			&& abs(ene->i - game->enemies[i]->i) < 16
			&& abs(ene->j - game->enemies[i]->j) < 16)
		{
			game->enemies[i]->type = 'M';
			game->enemies[i]->spd = 2;
			if (ft_dealloc_enemies(game, id) == -1)
			{
				ft_printf_err("Error: Merging to M", 1);
				ft_end(game, -1);
			}
			return (1);
		}
	}
	return (0);
}
