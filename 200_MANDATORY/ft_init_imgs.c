/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:24:46 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 13:24:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static int	ft_load_img(t_gobj *game, char *filename)
{
	char	*path;
	void	*img;
	t_ints	i;

	path = ft_strjoin("999_GOBJ/img/", filename);
	if (!path)
	{
		ft_printf_err("A problem occured", 1);
		return (-1);
	}
	img = mlx_xpm_file_to_image(game->mlx, path, &(i.x), &(i.y));
	free(path);
	i.i = -1;
	while (game->imgs[++(i.i)])
		;
	game->imgs[i.i] = img;
	return (game->imgs[i.i] != NULL);
}

static int	ft_img_err(void)
{
	ft_printf("Missing image. Be sure to get all images installed.\n");
	return (-1);
}

int	ft_init_imgs(t_gobj *game)
{
	int	count;

	count = 5;
	game->imgs = ft_calloc(count + 1, sizeof(void *));
	if (!game->imgs)
		return (-1);
	if (!ft_load_img(game, "floor_m.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "wall_m.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "player1_m.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "coin_m.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "exit_m.xpm"))
		return (ft_img_err());
	return (count);
}
