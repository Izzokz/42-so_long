/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:02:10 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/13 19:02:13 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	unicornize_screen(char *data, t_ints *d)
{
	int	r_mult;

	r_mult = ft_random(3);
	d->i = -1;
	while (++(d->i) < d->len)
	{
		d->j = -1;
		while (++(d->j) < d->height)
		{
			d->k = (d->j * d->len) + (d->i * d->count / 8);
			if (d->j % 9 < 3 && d->j != 0)
				*(unsigned int *)(data + d->k) = 0xFFFFFF * r_mult;
			else if (d->j % 9 < 6 && d->j != 0)
				*(unsigned int *)(data + d->k) = 0xa3e8ff * r_mult;
			else
				*(unsigned int *)(data + d->k) = 0xa3ffbc * r_mult;
		}
	}
}

void	ft_screen_form(t_gobj *game)
{
	t_ints	d;
	char	*data;

	if (!game->screen_form)
		game->screen_form = mlx_new_image(game->mlx,
				game->win_i, game->win_j);
	if (!game->screen_form)
	{
		ft_printf_err("We had issue generating the screen form.", 1);
		ft_end(game, -1);
	}
	data = mlx_get_data_addr(game->screen_form, &(d.count), &(d.len), &(d.z));
	if (!data)
	{
		ft_printf_err("A problem ocured: ft_screen_form.c:47", 1);
		ft_end(game, -1);
	}
	d.height = game->win_j;
	unicornize_screen(data, &d);
}
