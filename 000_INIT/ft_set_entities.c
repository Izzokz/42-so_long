/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_entities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:32 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/16 14:35:11 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_clone_enemies(t_enemy ***from, t_enemy ***to)
{
	int	i;

	i = -1;
	while (*from && (*from)[++i])
	{
		(*to)[i] = ft_calloc(1, sizeof(t_enemy));
		if (!(*to)[i])
		{
			ft_free_enemies(to);
			ft_free_enemies(from);
			return (-1);
		}
		((*to)[i])->i = ((*from)[i])->i;
		((*to)[i])->j = ((*from)[i])->j;
		((*to)[i])->spd = ((*from)[i])->spd;
		((*to)[i])->type = ((*from)[i])->type;
		((*to)[i])->active = ((*from)[i])->active;
		((*to)[i])->q_pass = ((*from)[i])->q_pass;
	}
	return (0);
}

static int	ft_add_enemy(t_gobj *game, t_enemy *ene)
{
	t_enemy	**tmp;
	int		len;

	len = 0;
	while (game->enemies && game->enemies[len])
		len++;
	tmp = ft_calloc(len + 2, sizeof(t_enemy *));
	if (!tmp)
		return (-1);
	if (ft_clone_enemies(&(game->enemies), &tmp) == -1)
		return (-1);
	len = 0;
	while (tmp[len])
		len++;
	tmp[len] = ene;
	ft_free_enemies(&(game->enemies));
	game->enemies = ft_calloc(len + 2, sizeof(t_enemy *));
	if (ft_clone_enemies(&tmp, &(game->enemies)) == -1)
		return (-1);
	ft_free_enemies(&tmp);
	return (0);
}

static void	ft_create_enemy(t_gobj *game, char type, int i, int j)
{
	t_enemy	*ene;

	ene = ft_calloc(1, sizeof(t_enemy));
	if (!ene)
	{
		ft_printf_err("We had issue handling enemies", 1);
		ft_end(game, -1);
	}
	ene->active = 1;
	ene->type = type;
	ene->i = j * 32 + 8;
	ene->j = i * 32 + 8;
	ene->spd = 1.0f;
	ene->q_pass = 0;
	if (ft_add_enemy(game, ene) == -1)
	{
		ft_printf_err("We had issue adding an enemy", 1);
		ft_end(game, -1);
	}
	if (type == 'Q')
		game->str.map[i][j] = '0';
	else if (type == 'q')
		game->str.map[i][j] = '+';
	else
		game->str.map[i][j] = '-';
}

void	ft_set_enemies(t_gobj *game)
{
	t_ints	i;

	i.x = -1;
	while (game->str.map[++(i.x)])
	{
		i.y = -1;
		while (game->str.map[i.x][++(i.y)])
		{
			if (game->str.map[i.x][i.y] == 'Q')
				ft_create_enemy(game, 'Q', i.x, i.y);
			if (game->str.map[i.x][i.y] == 'q')
				ft_create_enemy(game, 'q', i.x, i.y);
		}
	}
}

void	ft_set_players(t_gobj *game)
{
	t_ints	i;

	i.x = -1;
	while (game->str.map[++(i.x)])
	{
		i.y = -1;
		while (game->str.map[i.x][++(i.y)])
		{
			if (game->str.map[i.x][i.y] == 'P')
			{
				game->p1->i = i.y * 32 + 8;
				game->p1->j = i.x * 32 + 8;
				game->str.map[i.x][i.y] = '0';
			}
			if (game->str.map[i.x][i.y] == '@')
			{
				game->p2->i = i.y * 32 + 8;
				game->p2->j = i.x * 32 + 8;
				game->str.map[i.x][i.y] = '-';
			}
		}
	}
}
