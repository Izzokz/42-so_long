/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_to_dmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:46:41 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/10 18:46:43 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_copy_to_dmap(t_gobj *game, void *img, int i, int j)
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

void	ft_print_entities(t_gobj *game)
{
	if (!game->p1->finish)
		ft_copy_to_dmap(game, game->imgs[2], game->p1->i, game->p1->j);
	if (!game->p2->finish)
		ft_copy_to_dmap(game, game->imgs[7], game->p2->i, game->p2->j);
}