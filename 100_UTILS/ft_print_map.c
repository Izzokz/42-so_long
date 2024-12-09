/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:11:32 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:49:23 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			if (!((*(unsigned int *)(data + d.j) & 0xFFFFFF) == 0x000000))
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

void	ft_print_map(t_gobj *game)
{
	t_ints	i;

	ft_gen_dmap(game);
	i.i = -1;
	while (game->str.map[++(i.i)])
	{
		i.j = -1;
		while (game->str.map[i.i][++(i.j)])
		{
			if (game->str.map[i.i][i.j] == '0'
				|| game->str.map[i.i][i.j] == 'C')
				ft_copy_to_dmap(game, game->imgs[0], i.j * 32, i.i * 32);
			if (game->str.map[i.i][i.j] == '1')
				ft_copy_to_dmap(game, game->imgs[1], i.j * 32, i.i * 32);
			if (game->str.map[i.i][i.j] == 'C')
				ft_copy_to_dmap(game, game->imgs[3],
					i.j * 32 + 8, i.i * 32 + 8);
			if (game->str.map[i.i][i.j] == 'E')
				ft_copy_to_dmap(game, game->imgs[4], i.j * 32, i.i * 32);
		}
	}
	if (!(game->p1->finish))
		ft_copy_to_dmap(game, game->imgs[2], game->p1->i, game->p1->j);
	mlx_put_image_to_window(game->mlx, game->win, game->dmap, 0, 0);
}
