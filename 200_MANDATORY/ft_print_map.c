/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:42:54 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/07 15:42:55 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static void	ft_copy_to_dmap(t_gobj *game, void *img, int i, int j)
{
	t_ints	d;
	char	*data;
	char	*dmap_data;

	dmap_data = mlx_get_data_addr(game->dmap, &(d.count), &(d.len), &(d.z));
	data = mlx_get_data_addr(img, &(d.count1), &(d.len1), &(d.z));
	if (!dmap_data || !data)
	{
		ft_printf_err("A problem occured: ft_print_map.c: 21||22", 1);
		ft_end(game, -1);
	}
	d.x = i - 1;
	d.height = d.len1 / (d.count1 / 8);
	while (++(d.x) < i + d.height)
	{
		d.y = j - 1;
		while (++(d.y) < j + d.height)
		{
			d.k = (d.y * d.len) + (d.x * d.count / 8);
			d.j = ((d.y - j) * d.len1) + ((d.x - i) * d.count1 / 8);
			*(unsigned int *)(dmap_data + d.k)
				= *(unsigned int *)(data + d.j);
		}
	}
}

static void	ft_gen_dmap(t_gobj *game)
{
	if (!game->dmap)
		game->dmap = mlx_new_image(game->mlx, game->width * 32,
				game->height * 32);
	if (!game->dmap)
	{
		ft_printf_err("A problem occured: ft_print_map.c: 47", 1);
		ft_end(game, -1);
	}
}

static void	ft_call_copy(t_gobj *game, int i, int j)
{
	if (game->p1->i == j && game->p1->j == i)
		ft_copy_to_dmap(game, game->imgs[2], j * 32, i * 32);
	else if (game->map[i][j] == '0')
		ft_copy_to_dmap(game, game->imgs[0], j * 32, i * 32);
	else if (game->map[i][j] == '1')
		ft_copy_to_dmap(game, game->imgs[1], j * 32, i * 32);
	else if (game->map[i][j] == 'C')
		ft_copy_to_dmap(game, game->imgs[3], j * 32, i * 32);
	else if (game->map[i][j] == 'E')
		ft_copy_to_dmap(game, game->imgs[4], j * 32, i * 32);
}

void	ft_print_map(t_gobj *game)
{
	t_ints	i;

	ft_gen_dmap(game);
	i.i = -1;
	while (game->map[++(i.i)])
	{
		i.j = -1;
		while (game->map[i.i][++(i.j)])
			ft_call_copy(game, i.i, i.j);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->dmap, 0, 0);
}

void	ft_update_dmap(t_gobj *game, int i, int j)
{
	ft_call_copy(game, j, i);
	ft_call_copy(game, game->p1->j, game->p1->i);
	mlx_put_image_to_window(game->mlx, game->win, game->dmap, 0, 0);
}
