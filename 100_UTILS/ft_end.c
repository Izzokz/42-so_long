/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:03 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:48:26 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_str(t_str str)
{
	ft_free_rlines(&(str.map));
	ft_free_rlines(&(str.map_dep));
	ft_free_slines(&(str.msg));
}

void	ft_free_enemies(t_enemy ***enemies)
{
	int	i;

	if (!enemies || !(*enemies))
		return ;
	i = -1;
	while ((*enemies)[++i])
	{
		free((*enemies)[i]);
		(*enemies)[i] = NULL;
	}
	free(*enemies);
	*enemies = NULL;
}

void	ft_end(t_gobj *game, int exit_id)
{
	int		i;

	if (!game)
		exit(-1);
	i = -1;
	while (game->imgs && game->imgs[++i])
		mlx_destroy_image(game->mlx, game->imgs[i]);
	free(game->imgs);
	ft_free_enemies(&(game->enemies));
	if (game->dmap)
		mlx_destroy_image(game->mlx, game->dmap);
	if (game->screen_form)
		mlx_destroy_image(game->mlx, game->screen_form);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_free_str(game->str);
	if (game->current_map)
		free(game->current_map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(exit_id);
}
