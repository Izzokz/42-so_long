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

static void	ft_copy_pixel(t_gobj *game, unsigned int from, unsigned int *to)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	from *= game->theme;
	r = ((from >> 16) & 0xFF) * game->brn;
	g = ((from >> 8) & 0xFF) * game->brn;
	b = (from & 0xFF) * game->brn;
	r = r | ((255 - r) >> 31);
	g = g | ((255 - g) >> 31);
	b = b | ((255 - b) >> 31);
	*to = (from & 0xFF000000) | (r << 16) | (g << 8) | b;
}

static void	unicornize_screen(t_gobj *game, char *data, t_ints *d)
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
			if (d->j % 21 < 7 && d->j != 0)
				ft_copy_pixel(game, 0x32A8DD * r_mult,
					(unsigned int *)(data + d->k));
			else if (d->j % 21 < 14 && d->j != 0)
				ft_copy_pixel(game, 0x32A88F * r_mult,
					(unsigned int *)(data + d->k));
			else
				ft_copy_pixel(game, 0x32A8A6 * r_mult,
					(unsigned int *)(data + d->k));
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
	unicornize_screen(game, data, &d);
}

void	ft_change_screen_form(t_gobj *game)
{
	game->keys_state[XK_r] = 0;
	mlx_destroy_image(game->mlx, game->screen_form);
	game->screen_form = NULL;
	ft_screen_form(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen_form, 0, 0);
	ft_print_map(game);
	ft_print_stats(game);
}
